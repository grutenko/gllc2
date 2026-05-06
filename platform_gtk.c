#if defined(__linux__)

#include "platform.h"
#include <gtk/gtk.h>

static gboolean on_render(GtkGLArea *area, GdkGLContext *ctx, gpointer data) {
  struct nw *w = data;
  if (!ctx)
    return FALSE;
  gtk_gl_area_make_current(area);
  if (gtk_gl_area_get_error(area))
    return FALSE;
  w->cb_vtable_p->paint(w, w->data);
  return TRUE;
}

static gboolean on_configure(GtkWidget *widget, GtkAllocation *allocation, gpointer data) {
  struct nw *w = data;
  printf("%d, %d\n", allocation->width, allocation->height);
  w->cb_vtable_p->size(w, allocation->width, allocation->height, w->data);
  return TRUE;
}

static gboolean on_motion(GtkWidget *widget, GdkEventMotion *event, gpointer data) {
  struct nw *w = data;
  w->cb_vtable_p->mouse_move(w, (int)event->x, (int)event->y, w->data);
  return FALSE;
}

static gboolean on_button(GtkWidget *widget, GdkEventButton *event, gpointer data) {
  struct nw *w = data;
  gtk_widget_grab_focus(widget);
  int action = (event->type == GDK_BUTTON_PRESS) ? 1 : 0;
  int button = 1;
  if (event->button == 1) {
    button = 1;
  } else if (event->button == 2) {
    button = 3;
  } else if (event->button == 3) {
    button = 2;
  }
  w->cb_vtable_p->mouse_click(w, (int)event->x, (int)event->y, button, action, w->data);
  return TRUE;
}

static gboolean on_scroll(GtkWidget *widget, GdkEventScroll *event, gpointer data) {
  struct nw *w = data;
  int dx = 0, dy = 0;

  switch (event->direction) {
  case GDK_SCROLL_UP:
    dy = -1;
    break;
  case GDK_SCROLL_DOWN:
    dy = 1;
    break;
  case GDK_SCROLL_LEFT:
    dx = -1;
    break;
  case GDK_SCROLL_RIGHT:
    dx = 1;
    break;
  default:
    break;
  }
  w->cb_vtable_p->mouse_scroll(w, dx, dy, w->data);

  return TRUE;
}

static gboolean on_leave(GtkWidget *widget, GdkEventCrossing *event, gpointer data) {
  struct nw *w = data;
  // w->vtable->mouse_leave(w, w->data);
  return TRUE;
}

static gboolean on_ready(GtkGLArea *area, gpointer data) {
  struct nw *nw = data;
  GtkWidget *gl = GTK_WIDGET(nw->area);
  GdkWindow *win = gtk_widget_get_window(gl);
  if (win) {
    gdk_window_set_events(win, gdk_window_get_events(win) |
                                   GDK_POINTER_MOTION_MASK |
                                   GDK_BUTTON_PRESS_MASK |
                                   GDK_BUTTON_RELEASE_MASK |
                                   GDK_SCROLL_MASK |
                                   GDK_LEAVE_NOTIFY_MASK);

    gdk_window_set_event_compression(win, FALSE);
    gdk_window_raise(win);
  }
  nw->cb_vtable_p->ready(nw, nw->data);
  return TRUE;
}

static void destroy(struct nw *nw) {
  GtkWidget *widget = GTK_WIDGET(nw->area);
  gtk_widget_destroy(widget);
  nw->area = NULL;
}

static int set_cursor_pos(struct nw *nw, int x, int y) {
  /*
    GTK3/GDK специально НЕ поддерживает
    глобальный warping курсора нормально
    на Wayland.

    На X11 можно:
*/
#ifdef GDK_WINDOWING_X11
  GdkDisplay *display = gdk_display_get_default();
  GdkSeat *seat = gdk_display_get_default_seat(display);
  GdkDevice *pointer = gdk_seat_get_pointer(seat);
  gdk_device_warp(pointer, gdk_display_get_default_screen(display), x, y);
#endif
  return 1;
}

static int get_cursor_pos(struct nw *nw, int *x, int *y) {
  GdkDisplay *display = gtk_widget_get_display(GTK_WIDGET(nw->area));
  GdkSeat *seat = gdk_display_get_default_seat(display);
  GdkDevice *pointer = gdk_seat_get_pointer(seat);
  double px, py;
  gdk_window_get_device_position_double(
      gtk_widget_get_window(GTK_WIDGET(nw->area)),
      pointer,
      &px,
      &py,
      NULL);
  if (x)
    *x = (int)px;
  if (y)
    *y = (int)py;
  return 1;
}

static int make_context_current(struct nw *nw) {
  if (!gtk_widget_get_realized(GTK_WIDGET(nw->area))) {
    g_debug("GLArea is not realized");
    return 0;
  }
  gtk_gl_area_make_current(nw->area);
  return 1;
}

static int get_size(struct nw *nw, int *width, int *height) {
  GtkAllocation alloc;
  gtk_widget_get_allocation(GTK_WIDGET(nw->area), &alloc);
  if (width)
    *width = alloc.width;
  if (height)
    *height = alloc.height;
  return 1;
}

static int set_size(struct nw *nw, int width, int height) {
  GtkAllocation alloc;
  alloc.x = 0;
  alloc.y = 0;
  alloc.width = width;
  alloc.height = height;
  gtk_widget_set_size_request(GTK_WIDGET(nw->area), width, height);
  gtk_widget_size_allocate(GTK_WIDGET(nw->area), &alloc);
  return 1;
}

static int swap_buffers(struct nw *nw) {
  (void)nw;
  return 0;
}

static int dirty(struct nw *nw) {
  if (nw->area) {
    gtk_widget_queue_draw(GTK_WIDGET(nw->area));
    return 1;
  }
  return 0;
}

static int show_cursor(struct nw *nw, int show) {
  (void)nw;
  (void)show;
  return 0;
}

static int focus(struct nw *nw) {
  gtk_widget_grab_focus(GTK_WIDGET(nw->area));
  return 1;
}

static int poll_events(struct nw *nw) {
  (void)nw;
  return 0;
}

int nw_create_gtk(struct nw *nw, struct nw_callback_vtable *vtable, GtkWindow *parent, void *data) {
  g_assert(GTK_IS_WIDGET(parent));
  nw->area = GTK_GL_AREA(gtk_gl_area_new());
  nw->cb_vtable_p = vtable;
  nw->data = data;
  nw->vtable.destroy = destroy;
  nw->vtable.dirty = dirty;
  nw->vtable.focus = focus;
  nw->vtable.get_cursor_pos = get_cursor_pos;
  nw->vtable.set_cursor_pos = set_cursor_pos;
  nw->vtable.show_cursor = show_cursor;
  nw->vtable.get_size = get_size;
  nw->vtable.set_size = set_size;
  nw->vtable.make_context_current = make_context_current;
  nw->vtable.swap_buffers = swap_buffers;
  nw->vtable.poll_events = poll_events;
  gtk_gl_area_set_required_version(nw->area, 3, 3);
  gtk_gl_area_set_has_depth_buffer(nw->area, FALSE);
  if (GTK_IS_BIN(parent)) {
    GtkWidget *child = gtk_bin_get_child(GTK_BIN(parent));
    if (GTK_IS_BOX(child)) {
      if (child && GTK_IS_CONTAINER(child)) {
        GList *list = gtk_container_get_children(GTK_CONTAINER(child));
        gtk_container_add(GTK_CONTAINER(list->data), GTK_WIDGET(nw->area));
        gtk_widget_show(GTK_WIDGET(nw->area));
        gtk_widget_queue_resize(child);
        g_list_free(list);
      }
    } else {
      gtk_container_add(GTK_CONTAINER(parent), GTK_WIDGET(nw->area));
    }
  } else {
    gtk_container_add(GTK_CONTAINER(parent), GTK_WIDGET(nw->area));
  }
  g_assert(gtk_widget_get_parent(GTK_WIDGET(nw->area)) != NULL);
  GtkWidget *gl = GTK_WIDGET(nw->area);
  gtk_widget_show(gl);
  gtk_widget_set_can_focus(gl, TRUE);
  gtk_widget_set_sensitive(gl, TRUE);
  gtk_widget_set_focus_on_click(gl, TRUE);
  gtk_widget_add_events(gl, GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_SCROLL_MASK);
  g_signal_connect(gl, "realize", G_CALLBACK(on_ready), nw);
  g_signal_connect(gl, "render", G_CALLBACK(on_render), nw);
  g_signal_connect(gl, "size-allocate", G_CALLBACK(on_configure), nw);
  g_signal_connect(gl, "motion-notify-event", G_CALLBACK(on_motion), nw);
  g_signal_connect(gl, "button-press-event", G_CALLBACK(on_button), nw);
  g_signal_connect(gl, "button-release-event", G_CALLBACK(on_button), nw);
  g_signal_connect(gl, "scroll-event", G_CALLBACK(on_scroll), nw);
  g_signal_connect(gl, "leave-notify-event", G_CALLBACK(on_leave), nw);
  GtkAllocation allocation;
  gtk_widget_get_allocation(GTK_WIDGET(parent), &allocation);
  gtk_widget_set_size_request(gl, allocation.width, allocation.height);
  g_idle_add((GSourceFunc)gtk_widget_queue_draw, gl);
  return 1;
}

#endif