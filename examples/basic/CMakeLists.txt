add_executable(basic_example main.c)
target_include_directories(basic_example PUBLIC ../../)
target_link_libraries(basic_example PRIVATE gllc)

add_custom_command(TARGET basic_example POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:gllc>
    $<TARGET_FILE_DIR:basic_example>
)

if (WIN32)
  target_compile_definitions(basic_example PRIVATE WIN32 _WIN32 _AMD64_ _CRT_SECURE_NO_WARNINGS)
  target_link_libraries(basic_example PRIVATE opengl32 gdi32 user32 kernel32)
endif()