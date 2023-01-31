//
// Created by vitor on 25/01/2023.
//

#include "GLFW/glfw3.h"

#ifndef GAME_ENGINE_PROJECT_WINDOW_H
#define GAME_ENGINE_PROJECT_WINDOW_H

class GameWindow {
public:
    GameWindow(int width, int height, const char* title);

    void Destroy();

    int ShouldClose();
    void Update();

    void ProcessInput();

    static int Initialize();
    static void Finalize();
private:
    GLFWwindow* _createdWindow;

    static void SetViewport(GLFWwindow* window, int width, int height);
};
#endif //GAME_ENGINE_PROJECT_WINDOW_H
