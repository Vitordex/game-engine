#include <glad/glad.h>
#include "include/GameWindow.h"

int main() {
    int initialized = GameWindow::Initialize();
    if (initialized == 0) return 1;

    GameWindow gameWindow(800, 600, "Test");

    glClearColor(0.f, 0.f, 0.f, 1.f);
    while (!gameWindow.ShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        gameWindow.Update();
    }

    GameWindow::Finalize();

    return 0;
}