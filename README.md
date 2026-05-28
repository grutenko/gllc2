## Контекст OpenGL

GLLC2 не создаёт верхнеуровневое окно приложения и не управляет жизненным циклом основного окна.

Внешнее приложение создаёт родительское окно и передаёт его в библиотеку.

## Системные требования

* C11 совместимый компилятор (GCC / Clang / MSVC)
* OpenGL 3.3+
* Поддержка создания OpenGL-контекста на стороне приложения
* CMake (с поддержкой presets)
* Windows / Linux (X11 или GTK-based интеграция)
* Wayland через EGL (опционально, через backend слой)

## Клонирование

```bash
git clone --recurse-submodules https://github.com/grutenko/gllc2
```

## Сборка (Linux)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Сборка (Windows)

### Требования

* Perl toolchain (используется в сборке; включает MinGW-w64 GCC и Perl в составе окружения)
* CMake с поддержкой presets

### Presets

Доступны конфигурации:

* `debug-win32`
* `release-win32`

### Сборка через preset

```bash
cmake --preset debug-win32
cmake --build --preset debug-win32
```

или

```bash
cmake --preset release-win32
cmake --build --preset release-win32
```

## Сборка (Linux)

### Presets

* `debug-linux`
* `release-linux`

### Сборка через preset

```bash
cmake --preset debug-linux
cmake --build --preset debug-linux
```

или

```bash
cmake --preset release-linux
cmake --build --preset release-linux
```

## Инициализация

### C API

```c
lcCreateWindow(parent_window_handle, flags);
```

### Python binding (пример)

```python
import sys
import litecad as lc

if sys.platform == "win32":
    hWnd = lc.lcCreateWindow(int(p.GetHandle()), 0)

elif sys.platform == "linux":
    hWnd = lc.lcCreateWindow(
        int(p.GetGtkWidget()),
        lc.XLC_WINDOW_GTK_BACKEND
    )
```

## Модель окна

Библиотека создаёт **дочернее окно внутри переданного родительского окна** и инициализирует в нём OpenGL-контекст.

## platform_handle

`parent_window_handle` — нативный хендл родительского окна:

* Windows: HWND (родительское Win32 окно)
* Linux (GTK/X11): native widget / X11 Window через GTK backend слой
* Wayland: интеграция через backend-абстракцию (EGL surface)

OpenGL-контекст создаётся внутри дочернего окна, управляемого библиотекой.

## Модель работы

* внешнее приложение создаёт родительское окно
* передаёт его в `lcCreateWindow`
* библиотека создаёт дочернее окно внутри него
* в дочернем окне создаётся OpenGL-контекст
* дальнейший рендер выполняется внутри GLLC2
