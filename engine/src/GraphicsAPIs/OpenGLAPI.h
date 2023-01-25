//
// Created by vitor on 25/01/2023.
//

#ifndef GAME_ENGINE_PROJECT_OPENGLAPI_H
#define GAME_ENGINE_PROJECT_OPENGLAPI_H


#include "GraphicsAPI.h"
#include "../Types/Color.h"

class OpenGLAPI : public GraphicsAPI {
public:
    void Clear() override;
    void ClearBackground(Color color) override;
};


#endif //GAME_ENGINE_PROJECT_OPENGLAPI_H
