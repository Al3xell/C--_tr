#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <vector>
#include <string>

#include "color.hpp"

namespace s5loo
{
    class Image
    {
    private:
        std::string name_;
        int width_, height_;
        std::vector<Color> pixel_;
    public:

        Image(std::string name, int width, int height, bool random = true);
        ~Image() = default;
    };
    
}
#endif // !IMAGE_HPP