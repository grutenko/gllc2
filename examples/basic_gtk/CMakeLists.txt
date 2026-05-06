add_executable(basic_gtk main.c)
target_link_libraries(basic_gtk PRIVATE gllc)
find_package(PkgConfig REQUIRED)
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
target_include_directories(basic_gtk PRIVATE ${GTK3_INCLUDE_DIRS})
target_link_libraries(basic_gtk PRIVATE ${GTK3_LIBRARIES} X11::X11)
target_compile_options(basic_gtk PRIVATE ${GTK3_CFLAGS_OTHER})
target_link_libraries(basic_gtk PRIVATE dl m)

add_custom_command(TARGET basic_gtk POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:gllc>
    $<TARGET_FILE_DIR:basic_gtk>
)