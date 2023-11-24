cmake_minimum_required(VERSION 3.24)
project(game_engine)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "include/.h" "src/.c")

set(MY_RESOURCE_FILES
        shaders/default.fshader
        shaders/default.vshader
)

FOREACH (MY_RESOURCE_FILE ${MY_RESOURCE_FILES})
    add_custom_command(
            OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${MY_RESOURCE_FILE}
            COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_SOURCE_DIR}/${MY_RESOURCE_FILE}
            ${CMAKE_CURRENT_BINARY_DIR}/${MY_RESOURCE_FILE}
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${MY_RESOURCE_FILE}
    )
ENDFOREACH ()

add_executable(game_engine main.cpp ${SRC}
        src/GameWindow.cpp
        src/GameWindow.h
        src/GraphicsAPIs/GraphicsAPI.cpp
        src/GraphicsAPIs/GraphicsAPI.h
        src/GraphicsAPIs/OpenGLAPI.cpp
        src/GraphicsAPIs/OpenGLAPI.h
        src/Types/Color.h
        src/stb_image/stb_image.h
        src/stb_image/stb_image.cpp
        src/GraphicsAPIs/Shader.cpp
        src/GraphicsAPIs/Shader.h
        src/GraphicsAPIs/Texture.h
        src/GraphicsAPIs/Texture.cpp
        src/utils/String.h
        src/utils/String.cpp)

target_link_libraries(game_engine glad)
target_link_libraries(game_engine glfw)