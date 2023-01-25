//
// Created by vitor on 25/01/2023.
//

#include "OpenGLAPI.h"
#include "glad/glad.h"

void OpenGLAPI::Clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLAPI::ClearBackground(Color color) {
    glClearColor(
            color.red,
            color.green,
            color.blue,
            color.alpha);
}