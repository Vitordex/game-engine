cmake_minimum_required(VERSION 3.24)
project(game_engine_project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/GLFW)
add_subdirectory(lib/GLAD)
add_subdirectory(engine)
