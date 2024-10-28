#pragma once

#include <string>


class Texture2D
{
public:
    bool load(const std::string& filepath, bool generateMipmaps = true);
    void bind(int unit = 0) const;

    Texture2D() = default;
    ~Texture2D() = default;

private:
    int width;
    int height;
    unsigned int id;
};
