#include <math.h>
#if defined(__linux__)
#include <gtk/gtk.h>
#include <gdk/gdkx.h> 

#include "litecad.h"

int main(int argc, char **argv) {
  gtk_init(&argc, &argv);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "NW App");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_realize(window); 
  GdkWindow *gdk_win = gtk_widget_get_window(window);
  void *hWnd = lcCreateWindow(window, XLC_WINDOW_GTK_BACKEND);
  void *hDrw = lcCreateDrawing();
  void *hBlock = lcPropGetHandle(hDrw, LC_PROP_DRW_BLOCK_MODEL);

  double n[2] = {1.0f, 0.0f};
  double a_step = M_PI / 1280.0f;
  for (int i = 0; i < 1280; i++) {
    n[0] = sin(i * a_step);
    n[1] = cos(i * a_step);
    void *pl = lcBlockAddLine(hBlock, n[0] * 1000.0f, n[1] * 1000.0f, -n[0] * 1000.0f, -n[1] * 1000.0f);
    struct gllc_object *o = (struct gllc_object *)pl;
    lcPropPutInt(o, LC_PROP_ENT_COLOR, 0x0);
  }
  lcBlockUpdate(hBlock, 1, 0);
  lcWndSetBlock(hWnd, hBlock);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

#endif