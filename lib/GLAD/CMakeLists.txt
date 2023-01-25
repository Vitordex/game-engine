cmake_minimum_required(VERSION 3.4.0)
project(GLAD VERSION 1.0.0)

add_library(glad include/glad/glad.h src/glad.c)

target_include_directories(glad PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_include_directories(glad PRIVATE
                           "src"
                           "${CMAKE_CURRENT_BINARY_DIR}/src")