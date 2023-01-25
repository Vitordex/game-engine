//
// Created by vitor on 25/01/2023.
//

#ifndef GAME_ENGINE_PROJECT_GRAPHICSAPI_H
#define GAME_ENGINE_PROJECT_GRAPHICSAPI_H

#include "../Types/Color.h"

class GraphicsAPI {
public:
    virtual void Clear();

    virtual void ClearBackground(Color color);
};


#endif //GAME_ENGINE_PROJECT_GRAPHICSAPI_H
