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
} // namespace s5loo
