//
// Created by vitor on 25/01/2023.
//

#ifndef GAME_ENGINE_PROJECT_COLOR_H
#define GAME_ENGINE_PROJECT_COLOR_H

struct Color {
    float red;
    float green;
    float blue;
    float alpha;

    static Color Black() {
        return {0.f, 0.f, 0.f, 1.f};
    }
};

#endif //GAME_ENGINE_PROJECT_COLOR_H
