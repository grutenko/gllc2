cmake_minimum_required(VERSION 3.18)
project(gllc C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    glad.c
    debug.c
    block.c
    circle.c
    event.c
    font.c
    linetype.c
    draw.c
    drawing.c
    entity.c
    linebuild.c
    object.c
    named_object.c
    platform_windows.c
    platform_gtk.c
    platform_webgl.c
    point.c
    polyline.c
    rect.c
    arc.c
    linalg.c
    entbuildutil.c
    sparsegrid.c
    stb_truetype.c
    ui_cursor.c
    ui_grid.c
    ui_selection.c
    ui_vertex_buffer.c
    layer.c
    window.c
    line.c
    litecad.c)
set(TESS2_SOURCES
    tess2/bucketalloc.c
    tess2/dict.c
    tess2/geom.c
    tess2/mesh.c
    tess2/priorityq.c
    tess2/sweep.c
    tess2/tess.c)

set(CGLM_STATIC ON)
add_subdirectory(cglm)
add_subdirectory(tools)
add_subdirectory(examples)

include_directories(. cglm/include ${CMAKE_BINARY_DIR})

set(SHADERS
    shaders/frag.frag
    shaders/vert.vert)

set(GENERATED_HEADERS "")
foreach(SHADER ${SHADERS})
    get_filename_component(NAME ${SHADER} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    add_custom_command(
        OUTPUT ${OUT}
        COMMAND $<TARGET_FILE:gen_shader_h> ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} ${OUT}
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
        COMMAND $<TARGET_FILE:gen_font_h> ${CMAKE_CURRENT_SOURCE_DIR}/${FONT} ${OUT}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${FONT} gen_font_h
        COMMENT "Generating header ${OUT} from ${FONT}"
        VERBATIM
    )

    list(APPEND GENERATED_FONT_HEADERS ${OUT})
endforeach()

add_custom_target(Fonts ALL DEPENDS ${GENERATED_FONT_HEADERS})

add_library(gllc SHARED ${SOURCES} ${TESS2_SOURCES})

target_include_directories(gllc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    cglm/include
)

target_compile_definitions(gllc PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)

target_compile_options(gllc PRIVATE
    $<$<CONFIG:Release>:-O2>
)

target_link_libraries(gllc PRIVATE cglm)

if (WIN32)
    target_link_libraries(gllc PRIVATE opengl32 gdi32 user32 kernel32)
elseif(UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk+-3.0)
    pkg_check_modules(EPOXY REQUIRED IMPORTED_TARGET epoxy)
    target_link_libraries(gllc PRIVATE PkgConfig::GTK)
target_link_libraries(gllc PRIVATE PkgConfig::EPOXY)
    find_package(OpenGL REQUIRED)

target_link_libraries(gllc PRIVATE OpenGL::GL)
    target_link_libraries(gllc PRIVATE m dl pthread)
    target_compile_options(gllc PRIVATE -fvisibility=hidden)
    target_compile_options(gllc PUBLIC -DGL_GLEXT_PROTOTYPES) 
endif()