cmake_minimum_required(VERSION 3.18)
project(gllc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_PLATFORM_NO_VERSIONED_SONAME TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Python3)

include_directories(include cglm/include ${CMAKE_BINARY_DIR})

file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)
file(GLOB TESS2SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/tess2/*.c"
)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CGLM_STATIC OFF)
add_subdirectory(cglm)
set(UTF8PROC_STATIC OFF)
add_subdirectory(utf8proc)
add_subdirectory(freetype)
set(HB_BUILD_GPU ON)
add_subdirectory(harfbuzz)

add_subdirectory(FreeImage)
if(NOT EMSCRIPTEN)
add_subdirectory(examples)
endif()
get_target_property(DEPS harfbuzz-gpu INTERFACE_LINK_LIBRARIES)
message(STATUS "${DEPS}")
message(STATUS "Python found at: ${Python3_EXECUTABLE}")

function(generate_header INPUT OUTPUT EXTRA_ARGS)
    add_custom_command(
        OUTPUT ${OUTPUT}
        COMMAND ${Python3_EXECUTABLE}
            ${CMAKE_SOURCE_DIR}/tools/xxdi.py
            ${INPUT}
            ${OUTPUT}
            ${EXTRA_ARGS}
        DEPENDS ${INPUT} ${CMAKE_SOURCE_DIR}/tools/xxdi.py
        COMMENT "Generating ${OUTPUT}"
        VERBATIM
    )
endfunction()

set(SHADERS
    shaders/frag.frag
    shaders/vert.vert)

set(GENERATED_HEADERS)

foreach(SHADER ${SHADERS})
    get_filename_component(NAME ${SHADER} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    generate_header(
        "${CMAKE_CURRENT_SOURCE_DIR}/${SHADER}"
        "${OUT}"
        "${NAME}_${NAME}"
    )

    list(APPEND GENERATED_HEADERS ${OUT})
endforeach()

set(GENERATED_FONT_HEADERS)

set(FONT_FILES
        fonts/Simplex.ttf
        fonts/mipgost.ttf)

foreach(FONT ${FONT_FILES})
    get_filename_component(NAME ${FONT} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    generate_header(
        "${CMAKE_CURRENT_SOURCE_DIR}/${FONT}"
        "${OUT}"
        "--binary"
    )

    list(APPEND GENERATED_FONT_HEADERS ${OUT})
endforeach()

if(NOT EMSCRIPTEN)
add_library(gllc SHARED ${SOURCES} ${TESS2SOURCES} ${GENERATED_HEADERS} ${GENERATED_FONT_HEADERS})
else()
add_library(gllc STATIC ${SOURCES} ${TESS2SOURCES} ${GENERATED_HEADERS} ${GENERATED_FONT_HEADERS})
endif()
target_compile_definitions(gllc PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)
target_compile_options(gllc PRIVATE
    $<$<CONFIG:Release>:-O2>
)

target_link_libraries(gllc PRIVATE cglm freetype utf8proc harfbuzz-gpu)

if (WIN32)
    target_link_libraries(gllc PRIVATE opengl32 gdi32 user32 kernel32)
elseif(UNIX)
    find_package(PkgConfig REQUIRED)
    if(EMSCRIPTEN)
      add_compile_options(-s USE_WEBGL2=1)
      add_link_options(-s USE_WEBGL2=1)
    else()
      pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk+-3.0)
      pkg_check_modules(EPOXY REQUIRED IMPORTED_TARGET epoxy)
      target_link_libraries(gllc PRIVATE PkgConfig::GTK)
      target_link_libraries(gllc PRIVATE PkgConfig::EPOXY)
      target_link_libraries(gllc PRIVATE m dl pthread)
      target_compile_options(gllc PRIVATE -fvisibility=hidden)
      target_compile_options(gllc PUBLIC -DGL_GLEXT_PROTOTYPES) 
    endif()
endif()

add_custom_target(copy_lib ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:gllc>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:gllc>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:harfbuzz>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:harfbuzz>"

COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:harfbuzz>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:harfbuzz-gpu>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:freetype>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:freetype>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:utf8proc>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:utf8proc>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:FreeImage>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:FreeImage>"

COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:cglm>
        "${CMAKE_SOURCE_DIR}/examples/python/$<TARGET_FILE_NAME:cglm>"

    COMMENT "Copying all runtime libs to python directory"
    VERBATIM
)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/compile_commands.json"
            "${CMAKE_SOURCE_DIR}/compile_commands.json"
        COMMENT "Copying compile_commands.json to source directory"
        VERBATIM
    )
endif()