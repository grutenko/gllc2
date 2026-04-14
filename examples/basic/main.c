#include "block.h"
#include "drawing.h"
#include "entity.h"
#include "litecad.h"
#include "object.h"
#include "polyline.h"
#include "window.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <winuser.h>

struct gllc_window *w;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
  case WM_SIZE:
    gllc_window_resize(w, 0, 0, LOWORD(lParam), HIWORD(lParam));
    return 0;
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

static float frand(float min, float max) {
  return min + (float)rand() / (float)RAND_MAX * (max - min);
}

unsigned int rand_color() {
  unsigned char r = rand() % 256;
  unsigned char g = rand() % 256;
  unsigned char b = rand() % 256;
  return (r << 16) | (g << 8) | b;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  srand((unsigned int)time(NULL));

  const char CLASS_NAME[] = "MyWindowClass";

  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd = CreateWindowEx(0, CLASS_NAME, "SimpleWindow", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                             NULL, NULL, hInstance, NULL);

  w = gllc_window_create(hwnd);
  if (!w) {
    printf("Cannot create window\n");
    return EXIT_FAILURE;
  }
  ShowWindow(hwnd, nCmdShow);

  struct gllc_drawing *drw = gllc_drw_create();
  struct gllc_block *block = gllc_drw_add_block(drw, "block1", 0, 0);

  int N = 600;
  int M = 600;
  double min = -1000.0;
  double max = 1000.0;
  double step = (max - min) / (double)N;
  double *tab = malloc(sizeof(double) * 2 * N * M);

  int i;
  int j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      int i0 = (i * M + j) * 2;
      tab[i0] = min + i * step;
      tab[i0 + 1] = min + j * step;
    }
  }

  for (i = 0; i < N - 1; i++) {
    for (j = 0; j < M - 1; j++) {
      int i0 = (i * M + j) * 2;
      int i1 = ((i + 1) * M + j) * 2;
      int i2 = ((i + 1) * M + (j + 1)) * 2;
      int i3 = (i * M + (j + 1)) * 2;
      struct gllc_polyline *pline = gllc_block_add_polyline(block, 1, rand() % 2);
      gllc_pline_add_ver(pline, tab[i0], tab[i0 + 1]);
      gllc_pline_add_ver(pline, tab[i1], tab[i1 + 1]);
      gllc_pline_add_ver(pline, tab[i2], tab[i2 + 1]);
      gllc_pline_add_ver(pline, tab[i3], tab[i3 + 1]);
      struct gllc_object *o = (struct gllc_object *)pline;
      gllc_prop_put_int(o, LC_PROP_ENT_COLOR, 0x0);
      gllc_prop_put_int(o, LC_PROP_ENT_FCOLOR, rand() % 0xffffff);
      gllc_prop_put_int(o, LC_PROP_ENT_FALPHA, 75);
      gllc_prop_put_int(o, LC_PROP_ENT_LWIDTH, LC_LW_PIXEL);
      gllc_prop_put_float(o, LC_PROP_ENT_LWIDTH, 2.0f);
    }
  }
  gllc_block_update(block);
  gllc_window_set_block(w, block);

  MSG msg;
  int running = 1;

  while (running) {
    WaitMessage();

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) {
        running = 0;
        break;
      }

      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  gllc_block_destroy(block);
  gllc_window_destroy(w);

  return 0;
}