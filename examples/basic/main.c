#include "block.h"
#include "drawing.h"
#include "entity.h"
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
  struct gllc_polyline *pline = gllc_block_add_polyline(block, 1, 0);
  float x = 0.0f;
  float y = 0.0f;

  for (int i = 0; i < 1000000; i++) {
    x += frand(-10.0f, 10.0f);
    y += frand(-10.0f, 10.0f);
    gllc_pline_add_ver(pline, x, y);
  }
  gllc_entity_set_color(&pline->_ent, 0xffffff);
  gllc_entity_set_fcolor(&pline->_ent, rand_color());
  pline->_ent.falpha = 0.3f;
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

  gllc_window_destroy(w);

  return 0;
}