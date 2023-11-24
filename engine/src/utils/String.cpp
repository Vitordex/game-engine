//
// Created by Vitor Ribeiro on 23/11/2023.
//

#include "String.h"

String::String(const char* content) {
    data = content;

    unsigned int index = 0;
    char c = data[index];
    while (c != '\0') {
        index++;
        c = data[index];
    }
    length = index;
}

bool String::contains(String* content) const {
    unsigned int index = 0;

    char currentChar = data[index];
    const unsigned int contentLength = content->length;

    const char contentFirstChar = content->get(0);
    while (currentChar != '\0') {
        if (contentFirstChar == currentChar) {
            bool equal = true;

            for (unsigned int i = 0; i < contentLength; i++) {
                if (data[index + i] == content->get(i)) continue;

                equal = false;
            }

            if (equal) return true;
        }

        index++;
        currentChar = data[index];
    }

    return false;
}

bool String::contains(const char* content) const {
    auto text = String(content);
    return contains(&text);
}

char String::get(const unsigned int index) const {
    if (index >= length) return '\0';

    return data[index];
}

const char* String::getData() const {
    return data;
}
