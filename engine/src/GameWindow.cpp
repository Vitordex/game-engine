//
// Created by vitor on 25/01/2023.
//
#include <glad/glad.h>
#include "GameWindow.h"

GameWindow::GameWindow(int width, int height, const char *title) {
    GLFWwindow *createdWindow = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(createdWindow);
    _createdWindow = createdWindow;
}

void GameWindow::Destroy() {
    glfwDestroyWindow(_createdWindow);
    _createdWindow = nullptr;
}

int GameWindow::Initialize() {
    int initialized = glfwInit();
    if (initialized == 0) return 1;

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GameWindow createdWindow(10, 10, "");
    int initGlad = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    createdWindow.Destroy();

    return initialized;
}

int GameWindow::ShouldClose() {
    return glfwWindowShouldClose(_createdWindow);
}

void GameWindow::Update() {
    glfwPollEvents();
    glfwSwapBuffers(_createdWindow);
}

void GameWindow::Finalize() {
    glfwTerminate();
}
