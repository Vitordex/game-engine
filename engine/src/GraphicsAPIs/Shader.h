//
// Created by Vitor Ribeiro on 13/11/2023.
//
#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    // the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // use/activate the shader
    void use() const;

    // utility uniform functions
    void setBool(const std::string&name, bool value) const;

    void setInt(const std::string&name, int value) const;

    void setFloat(const std::string&name, float value) const;
};
#endif
