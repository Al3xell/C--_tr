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
        Image(std::string path);
        Image() = default;
        Image(const Image &) = delete; //constructeur par recopie
        Image& operator=(const Image &) = delete; //affectation par recopie
        Image(Image &&) = default; //constructeur par déplacement
        Image& operator=(Image &&) = default; //affectation par déplacement
        ~Image() = default;
        const std::string& getName() const {return name_;}
        void setName(std::string name) {name_ = name;}
        void setWidth(int width);
        void setHeight(int height);
        void setPixels(std::vector<Color> pixels) {pixel_ = pixels;}
        const int& getWidth() const {return width_;}
        const int& getHeight() const {return height_;}
        const Color& operator[](int i) const
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
    std::ostream& operator<<(std::ostream& os,const Image& img);
    std::string imageName(std::string path);
    inline int size(const Image& img) {return img.getWidth()*img.getHeight();}
    void save(const Image& img);
    Image grey(const Image& img);
}
#endif // !IMAGE_HPP