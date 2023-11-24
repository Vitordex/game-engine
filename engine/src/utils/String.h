#pragma once

struct String {
private:
    const char* data;
    unsigned int length;

public:
    explicit String(const char* content);

    bool contains(String* content) const;

    bool contains(const char* content) const;

    [[nodiscard]] char get(unsigned int index) const;

    [[nodiscard]] const char* getData() const;
};
