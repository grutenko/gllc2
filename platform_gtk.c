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
  w->vtable->paint(w, w->data);
  return TRUE;
}

static gboolean on_configure(GtkWidget *widget, GtkAllocation *allocation, gpointer data) {
  struct nw *w = data;
  w->vtable->size(w, allocation->width, allocation->height, w->data);
  return FALSE;
}

static gboolean on_motion(GtkWidget *widget, GdkEventMotion *event, gpointer data) {
  struct nw *w = data;
  w->vtable->mouse_move(w, (int)event->x, (int)event->y, w->data);
  return FALSE;
}

static gboolean on_button(GtkWidget *widget, GdkEventButton *event, gpointer data) {
  struct nw *w = data;
  int action = (event->type == GDK_BUTTON_PRESS) ? 1 : 0;
  int button = 1;
  if (event->button == 1) {
    button = 1;
  } else if (event->button == 2) {
    button = 3;
  } else if (event->button == 3) {
    button = 2;
  }
  w->vtable->mouse_click(w, (int)event->x, (int)event->y, button, action, w->data);
  return FALSE;
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
  w->vtable->mouse_scroll(w, dx, dy, w->data);

  return FALSE;
}

static gboolean on_leave(GtkWidget *widget, GdkEventCrossing *event, gpointer data) {
  struct nw *w = data;
  // w->vtable->mouse_leave(w, w->data);
  return FALSE;
}

static gboolean on_ready(GtkGLArea *area, gpointer data) {
  struct nw *w = data;
  w->vtable->ready(w, w->data);
  return TRUE;
}

int nw_create_async(struct nw *NW, void *parent, struct nw_vtable *vtable, void *data) {
  if (!NW || !vtable)
    return 0;
  g_assert(GTK_IS_WIDGET(parent));
  NW->area = GTK_GL_AREA(gtk_gl_area_new());
  NW->vtable = vtable;
  NW->data = data;
  gtk_gl_area_set_required_version(NW->area, 3, 3);
  gtk_gl_area_set_has_depth_buffer(NW->area, FALSE);
  gtk_container_add(GTK_CONTAINER(parent), GTK_WIDGET(NW->area));
  g_assert(gtk_widget_get_parent(GTK_WIDGET(NW->area)) != NULL);

  GtkWidget *gl = GTK_WIDGET(NW->area);
  GdkWindow *win = gtk_widget_get_window(gl);
  if (win) {
    gdk_window_set_event_compression(win, FALSE);
  }
  gtk_widget_set_can_focus(gl, TRUE);
  gtk_widget_set_focus_on_click(gl, TRUE);
  gtk_widget_add_events(gl, GDK_POINTER_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_LEAVE_NOTIFY_MASK | GDK_SCROLL_MASK);
  g_signal_connect(gl, "realize", G_CALLBACK(on_ready), NW);
  g_signal_connect(gl, "render", G_CALLBACK(on_render), NW);
  g_signal_connect(gl, "size-allocate", G_CALLBACK(on_configure), NW);
  g_signal_connect(gl, "motion-notify-event", G_CALLBACK(on_motion), NW);
  g_signal_connect(gl, "button-press-event", G_CALLBACK(on_button), NW);
  g_signal_connect(gl, "button-release-event", G_CALLBACK(on_button), NW);
  g_signal_connect(gl, "scroll-event", G_CALLBACK(on_scroll), NW);
  g_signal_connect(gl, "leave-notify-event", G_CALLBACK(on_leave), NW);
  return 1;
}

void nw_destroy(struct nw *NW) {
  if (!NW)
    return;
  if (NW->area) {
    GtkWidget *widget = GTK_WIDGET(NW->area);
    gtk_widget_destroy(widget);
    NW->area = NULL;
  }
}

void nw_get_cursor(struct nw *w, int *x, int *y) {
  if (!w || !x || !y)
    return;
  GdkDisplay *display = gtk_widget_get_display(GTK_WIDGET(w->area));
  GdkSeat *seat = gdk_display_get_default_seat(display);
  GdkDevice *pointer = gdk_seat_get_pointer(seat);
  double px, py;
  gdk_window_get_device_position_double(
      gtk_widget_get_window(GTK_WIDGET(w->area)),
      pointer,
      &px,
      &py,
      NULL);
  *x = (int)px;
  *y = (int)py;
}

void nw_make_context_current(struct nw *w) {
  if (!w || !w->area)
    return;
  if (!gtk_widget_get_realized(GTK_WIDGET(w->area))) {
    g_debug("GLArea is not realized");
    return;
  }
  gtk_gl_area_make_current(w->area);
}

void nw_get_size(struct nw *w, int *width, int *height) {
  if (!w)
    return;
  GtkAllocation alloc;
  gtk_widget_get_allocation(GTK_WIDGET(w->area), &alloc);
  if (width)
    *width = alloc.width;
  if (height)
    *height = alloc.height;
}

void nw_set_size(struct nw *w, int x, int y, int width, int height) {
  (void)x;
  (void)y;
  if (!w)
    return;
  gtk_widget_set_size_request(GTK_WIDGET(w->area), width, height);
}

void nw_swap_buffers(struct nw *w) {
  (void)w;

  /*
        GtkGLArea сам делает swap buffers.
        Здесь ничего делать НЕ нужно.
    */
}

void nw_dirty(struct nw *w) {
  if (!w)
    return;

  gtk_gl_area_queue_render(w->area);
}

void nw_show_cursor(int show) {
  GdkDisplay *display = gdk_display_get_default();
  if (!display)
    return;
  GdkSeat *seat = gdk_display_get_default_seat(display);
  GdkDevice *pointer = gdk_seat_get_pointer(seat);
  GdkWindow *window = gdk_get_default_root_window();
  if (!window)
    return;
  if (show) {
    gdk_window_set_cursor(window, NULL);
  } else {
    GdkCursor *cursor = gdk_cursor_new_for_display(display, GDK_BLANK_CURSOR);
    gdk_window_set_cursor(window, cursor);
    g_object_unref(cursor);
  }
}

void nw_focus(struct nw *nw) {
  if (!nw)
    return;
  gtk_widget_grab_focus(GTK_WIDGET(nw->area));
}

void nw_cursor_set_pos(int x, int y) {
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
}

#endif