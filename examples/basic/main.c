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

  return 0;
}