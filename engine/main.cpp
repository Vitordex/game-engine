#include "glad/glad.h"
#include "src/GameWindow.h"
#include "src/GraphicsAPIs/Shader.h"
#include "src/GraphicsAPIs/Texture.h"
#include "src/GraphicsAPIs/GraphicsAPI.h"
#include "src/GraphicsAPIs/OpenGLAPI.h"

int main() {
    if (const int initialized = GameWindow::Initialize(); initialized == 0) return 1;

    GameWindow gameWindow(800, 600, "Test");
    OpenGLAPI graphicsApi;
    GraphicsAPI* api = &graphicsApi;

    const Shader ourShader("shaders/default.vshader", "shaders/default.fshader");

    constexpr float vertices[] = {
        // positions          // colors           // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
    };
    const unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    constexpr int vertices_length = 8;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
        vertices_length * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
        vertices_length * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
        vertices_length * sizeof(float), reinterpret_cast<void *>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    const Texture containerTexture("assets/container.jpg");
    const Texture smileTexture("assets/awesomeface.png");

    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);

    //    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);// Draw in wireframe mode
    //    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);// Draw in polygon filled mode

    api->ClearBackground({.2f, .3f, .3f, 1.f});
    while (!gameWindow.ShouldClose()) {
        gameWindow.ProcessInput();
        api->Clear();

        ourShader.use();

        containerTexture.use();
        smileTexture.use(1);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);

        gameWindow.Update();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    GameWindow::Finalize();

    return 0;
}
