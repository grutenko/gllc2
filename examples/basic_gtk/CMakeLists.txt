add_executable(basic_gtk main.c)
target_link_libraries(basic_gtk PRIVATE gllc)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    target_include_directories(basic_gtk PRIVATE ${GTK3_INCLUDE_DIRS})
    target_link_libraries(basic_gtk PRIVATE ${GTK3_LIBRARIES})
    target_compile_options(basic_gtk PRIVATE ${GTK3_CFLAGS_OTHER})
    target_link_libraries(basic_gtk PRIVATE ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} m dl pthread)

add_custom_command(TARGET basic_gtk POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:gllc>
    $<TARGET_FILE_DIR:basic_gtk>
)