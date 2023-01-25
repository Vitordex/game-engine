#include "src/GameWindow.h"
#include "src/GraphicsAPIs/GraphicsAPI.h"
#include "src/GraphicsAPIs/OpenGLAPI.h"
#include "src/Types/Color.h"

int main() {
    int initialized = GameWindow::Initialize();
    if (initialized == 0) return 1;

    GameWindow gameWindow(800, 600, "Test");
    OpenGLAPI graphicsApi;
    GraphicsAPI* api = &graphicsApi;

    api->ClearBackground(Color::Black());
    while (!gameWindow.ShouldClose()) {
        api->Clear();

        gameWindow.Update();
    }

    GameWindow::Finalize();

    return 0;
}