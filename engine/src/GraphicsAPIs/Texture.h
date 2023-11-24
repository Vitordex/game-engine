//
// Created by Vitor Ribeiro on 22/11/2023.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include "../utils/String.h"

class Texture {
public:
    explicit Texture(const char* imagePath);

    unsigned int ID{};

    void use(unsigned int index = 0) const;

private:
    int width;
    int height;
    int nrChannels;
};



#endif //TEXTURE_H
