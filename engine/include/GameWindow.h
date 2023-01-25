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

    static int Initialize();
private:
    GLFWwindow* _createdWindow;
};
#endif //GAME_ENGINE_PROJECT_WINDOW_H
