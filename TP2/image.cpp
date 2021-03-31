#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "image.hpp"
#include "color.hpp"

namespace s5loo
{
    Image::Image(std::string name, int width, int height, bool random)
           : name_(std::move(name)), width_(width), height_(height)
           {
               if(random)
               {
                   std::default_random_engine rndGen{std::random_device{}()};
                   std::uniform_int_distribution<int> component{0, 255};
                   for(int i = 0; i < width_*height_; i++)
                   {
                       uchar r = uchar(component(rndGen));
                       uchar g = uchar(component(rndGen));
                       uchar b = uchar(component(rndGen));
                       Color color = Color(r,g,b);
                       pixel_.emplace_back(std::move(color));
                   }
               }
               else for(int i = 0; i < width_*height_; i++) pixel_.emplace_back(Color());
           }
    std::ostream& operator<<(std::ostream& os,Image& img)
    {
        os << "name : " << img.getName() << "\n\nwidth : " << img.getWidth() << " height : " << img.getHeight() << "\n\n";
        for(int i = 0; i < size(img); i++) os << "pixel n°" << i << " : " << img[i] << "\n";
        return os;
    }
    void Image::setWidth(int width)
    {
        if(width < this->getWidth()) 
        {
            for(int i = width-1; i < this->width_; i++) this->pixel_.pop_back();
            this->width_ = width;
        }
        else if(width > this->getWidth())
        {
            for(int i = this->width_; i < width; i++) this->pixel_.emplace_back(Color());
            this->width_ = width;
        }
    }

    void Image::setHeight(int height)
    {
        if(height < this->getHeight()) 
        {
            for(int i = height-1; i < this->height_; i++) this->pixel_.pop_back();
            this->height_ = height;
        }
        else if(height > this->getHeight())
        {
            for(int i = this->height_; i < height; i++) this->pixel_.emplace_back(Color());
            this->height_ = height;
        }
    }
} // namespace s5loo
