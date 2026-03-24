cmake_minimum_required(VERSION 3.28)

project(gllc C)

set(SOURCES
  glad.c
  alloc.c
  block.c
  circle.c
  event.c
  font.c
  linetype.c
  draw.c
  drawing.c
  entity.c
  line_tess.c
  object.c
  platform_windows.c
  point.c
  polyline.c
  rect.c
  sparse_grid.c
  stb_truetype.c
  ui_cursor.c
  ui_grid.c
  ui_selection.c
  vertex.c
  window.c
  tess2/bucketalloc.c
  tess2/dict.c
  tess2/geom.c
  tess2/mesh.c
  tess2/priorityq.c
  tess2/sweep.c
  tess2/tess.c)

set(CGLM_STATIC ON)
add_subdirectory(cglm)

add_library(gllc SHARED ${SOURCES})
target_link_libraries(gllc PRIVATE cglm)


if (WIN32)
  target_compile_definitions(gllc PRIVATE WIN32 _WIN32 _AMD64_ _CRT_SECURE_NO_WARNINGS)
  target_link_libraries(gllc PRIVATE opengl32 gdi32 user32 kernel32)
endif()