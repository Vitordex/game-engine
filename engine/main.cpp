#include <glad/glad.h>
#include "include/GameWindow.h"

int main(int argc, char *argv[]) {
    int initialized = GameWindow::Initialize();
    if (initialized == 0) return 1;

    GameWindow createdWindow(10, 10, "");
    int initGlad = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    createdWindow.Destroy();

    if (initGlad == 0) return 1;

    GameWindow gameWindow(800, 600, "Test");

    glClearColor(0.f, 0.f, 0.f, 1.f);
    while (!gameWindow.ShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        gameWindow.Update();
    }

    glfwTerminate();
    gameWindow.Destroy();

    return 0;
}