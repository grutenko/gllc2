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
  lb.c
  object.c
  platform_windows.c
  point.c
  polyline.c
  rect.c
  sg.c
  stb_truetype.c
  tess.c
  ui_cursor.c
  ui_grid.c
  ui_selection.c
  ui_vertex.c
  window.c
  tess2/bucketalloc.c
  tess2/dict.c
  tess2/geom.c
  tess2/mesh.c
  tess2/priorityq.c
  tess2/sweep.c
  tess2/tess.c
  litecad.c)

set(ENV{LIBGL_ALWAYS_SOFTWARE} "1")
set(ENV{MESA_LOADER_DRIVER_OVERRIDE} "llvmpipe")

include_directories(. ${CMAKE_BINARY_DIR})

set(CGLM_STATIC ON)
add_subdirectory(cglm)
add_subdirectory(tools)


set(SHADERS
    shaders/vert.glsl
    shaders/frag.glsl
)

set(GENERATED_HEADERS "")

foreach(SHADER ${SHADERS})
    get_filename_component(NAME ${SHADER} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    add_custom_command(
        OUTPUT ${OUT}
        COMMAND gen_shader_h ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} ${OUT}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} gen_shader_h
        COMMENT "Generating header for ${SHADER}"
        VERBATIM
    )

    list(APPEND GENERATED_HEADERS ${OUT})
endforeach()

add_custom_target(Shaders ALL DEPENDS ${GENERATED_HEADERS})

set(FONT_FILES fonts/Simplex.ttf)

foreach(FONT ${FONT_FILES})
    get_filename_component(NAME ${FONT} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    add_custom_command(
        OUTPUT ${OUT}
        COMMAND gen_font_h ${CMAKE_CURRENT_SOURCE_DIR}/${FONT} ${OUT}
        DEPENDS ${FONT} gen_font_h
        COMMENT "Generating header ${OUT} from ${FONT}"
        VERBATIM
    )

    list(APPEND GENERATED_FONT_HEADERS ${OUT})
endforeach()

add_custom_target(Fonts ALL DEPENDS ${GENERATED_FONT_HEADERS})

add_library(gllc SHARED ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(gllc PRIVATE DEBUG)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(gllc PRIVATE NDEBUG)
endif()

target_compile_options(gllc PRIVATE
    $<$<CONFIG:Release>:-O2 -DNDEBUG>
)

target_link_libraries(gllc PRIVATE cglm)
target_include_directories(gllc PUBLIC cglm/include)

if (WIN32)
  target_compile_definitions(gllc PRIVATE WIN32 _WIN32 _AMD64_ _CRT_SECURE_NO_WARNINGS)
  target_link_libraries(gllc PRIVATE opengl32 gdi32 user32 kernel32)
endif()
add_subdirectory(examples)