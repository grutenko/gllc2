#if defined(_WIN32)

#include "litecad.h"

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
    lcWndResize(w, 0, 0, LOWORD(lParam), HIWORD(lParam));
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

  w = lcCreateWindow(hwnd, 0);
  if (!w) {
    printf("Cannot create window\n");
    return EXIT_FAILURE;
  }
  ShowWindow(hwnd, nCmdShow);

  struct gllc_drawing *drw = lcCreateDrawing();
  struct gllc_block *block = lcDrwAddBlock(drw, "block1", 0, 0);

  double n[2] = {1.0f, 0.0f};
  double a_step = M_PI / 1.0f;
  for (int i = 0; i < 1; i++) {
    n[0] = sin(i * a_step);
    n[1] = cos(i * a_step);
    double p0[2];
    double p1[2];
    p0[0] = n[0] * 1000.0f;
    p0[1] = n[1] * 1000.0f;
    p1[0] = -n[0] * 1000.0f;
    p1[1] = -n[1] * 1000.0f;
    struct gllc_line *pl = lcBlockAddLine(block, p0[0], p0[1], p1[0], p1[1]);
    struct gllc_object *o = (struct gllc_object *)pl;
    lcPropPutInt(o, LC_PROP_ENT_COLOR, 0x0);
  }
  lcBlockUpdate(block, 0, NULL);
  lcWndSetBlock(w, block);

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

  lcDeleteWindow(w);
  return 0;
}

#else

int main() {
  return 0;
}

#endif