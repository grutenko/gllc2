# GLLC - Graphics Library for CAD

Кроссплатформенная библиотека для создания OpenGL-окна и реализации CAD-логики.

## Описание

GLLC - кроссплатформенная библиотека, предоставляющая:

- Создание OpenGL-окна с возможностью встраивания в wxWidgets/Qt/GTK
- Базовые примитивы для 2D отрисовки
- Управление видами (зум, панорамирование)
- Выбор объектов

## Системные требования

| Платформа | Компилятор |
|-----------|------------|
| Windows | MinGW (GCC) |
| Linux | GCC |

## Сборка

```bash
git clone https://github.com/grutenko/gllc2.git
cd gllc
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4
sudo make install
```

## Сборка

### Linux

Требования:

- GCC 9 или новее
- CMake 3.10 или новее
- OpenGL development libraries
- X11 development libraries
- GTK development libraries (опционально, для встраивания)

Установка зависимостей:

```bash
# Ubuntu/Debian
sudo apt install build-essential cmake libgl1-mesa-dev libglu1-mesa-dev libx11-dev libgtk-3-dev

# Fedora/RHEL
sudo dnf install gcc-c++ cmake mesa-libGL-devel libX11-devel gtk3-devel

# Arch Linux
sudo pacman -S gcc cmake mesa libx11 gtk3
```

Сборка:
```bash
git clone --recurse-submodules https://github.com/grutenko/gllc2.git
cd gllc
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
sudo make install
```

Требования:
* MinGW-w64 (GCC)
* CMake 3.10 или новее
* OpenGL
* Windows SDK
Установка MinGW-w64:

```bash
# Через MSYS2
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-make
```

Сборка:
```bash
git clone --recurse-submodules https://github.com/grutenko/gllc2.git
cd gllc
mkdir build && cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
mingw32-make -j$(nproc)
mingw32-make install
```

_Msys MinGW64 должен быть установлен в C:/msys64/mingw64. В переменных среды должна быть запись C:/msys64/mingw64/bin_
