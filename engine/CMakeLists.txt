cmake_minimum_required(VERSION 3.24)
project(game_engine)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "include/.h" "src/.c")

add_executable(game_engine main.cpp ${SRC} src/GameWindow.cpp include/GameWindow.h)

target_link_libraries(game_engine glad)
target_link_libraries(game_engine glfw)