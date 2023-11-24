//
// Created by Vitor Ribeiro on 22/11/2023.
//

#include "Texture.h"
#include "../utils/String.h"

#include "../../../lib/GLAD/include/glad/glad.h"
#include "../stb_image/stb_image.h"

#include <iostream>

Texture::Texture(const char* imagePath) {
    stbi_set_flip_vertically_on_load(true);

    unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data) {
        const String pathString = String(imagePath);
        const int format = pathString.contains("png") ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        printf("Failed to load texture!");
    }

    stbi_image_free(data);
}

void Texture::use(const unsigned int index) const {
    if (index > 31) {
        printf("Cannot use texture index bigger than 31 using %d", index);
        return;
    }

    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, ID);
}
