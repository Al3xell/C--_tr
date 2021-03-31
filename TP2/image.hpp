#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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
        const std::string& getName() {return name_;}
        void setName(std::string name) {name_ = name;}
        void setWidth(int width);
        void setHeight(int height);
        const int& getWidth() {return width_;}
        const int& getHeight() {return height_;}
        Color& operator[](int i) 
        {
            try
            {
                if(i>=0 && i<width_*height_) return pixel_[i];
                else throw std::out_of_range{"please put an indices between 0 and his size"};
                
            }
            catch(const std::out_of_range &e)
            {
                std::cout << e.what() << '\n';
                std::exit(0);
            }
            
        }

    };
    std::ostream& operator<<(std::ostream& os,Image& img);
    inline int size(Image& img) {return img.getWidth()*img.getHeight();}
}
#endif // !IMAGE_HPP