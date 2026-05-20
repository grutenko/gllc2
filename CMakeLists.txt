cmake_minimum_required(VERSION 3.18)
project(gllc C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include cglm/include ${CMAKE_BINARY_DIR})

file(GLOB SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)
file(GLOB TESS2SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/tess2/*.c"
)
set(CGLM_STATIC ON)
add_subdirectory(cglm)
if(NOT EMSCRIPTEN)
add_subdirectory(examples)
endif()

set(SHADERS
    shaders/frag.frag
    shaders/vert.vert)

set(GENERATED_HEADERS "")
foreach(SHADER ${SHADERS})
    get_filename_component(NAME ${SHADER} NAME_WE)
    set(OUT "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.h")

    add_custom_command(
        OUTPUT ${OUT}
        COMMAND python ${CMAKE_SOURCE_DIR}/tools/xxdi.py ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER} ${OUT} ${NAME}_${NAME}
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
        COMMAND python ${CMAKE_SOURCE_DIR}/tools/xxdi.py ${CMAKE_CURRENT_SOURCE_DIR}/${FONT} ${OUT} --binary 
        COMMENT "Generating header ${OUT} from ${FONT}"
        VERBATIM
    )

    list(APPEND GENERATED_FONT_HEADERS ${OUT})
endforeach()
add_custom_target(Fonts ALL DEPENDS ${GENERATED_FONT_HEADERS})

if(NOT EMSCRIPTEN)
add_library(gllc SHARED ${SOURCES} ${TESS2_SOURCES})
else()
add_library(gllc STATIC ${SOURCES} ${TESS2_SOURCES})
endif()
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

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/compile_commands.json"
            "${CMAKE_SOURCE_DIR}/compile_commands.json"
        COMMENT "Copying compile_commands.json to source directory"
        VERBATIM
    )
endif()