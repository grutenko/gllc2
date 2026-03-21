cmake_minimum_required(VERSION 3.28)

project(gllc C)

set(SOURCES
  glad.c
  engine.c
  tess2/bucketalloc.c
  tess2/dict.c
  tess2/geom.c
  tess2/mesh.c
  tess2/priorityq.c
  tess2/sweep.c
  tess2/tess.c)

add_subdirectory(cglm)

add_library(gllc SHARED ${SOURCES})
target_link_libraries(gllc PRIVATE cglm)