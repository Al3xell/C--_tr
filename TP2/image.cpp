#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

#include "image.hpp"
#include "color.hpp"

namespace s5loo
{
    Image::Image(std::string name, int width, int height, bool random)
           : name_(std::move(name)), width_(width), height_(height), pixel_{}
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
    Image::Image(std::string path) : name_(imageName(path)), width_{},height_{},pixel_{}
    {
        std::ifstream flux(path);
        try 
        {
            if(!flux){throw std::runtime_error{"Can't open file on " + path + "\n"};}
            else
            {
                
                flux.seekg(3, std::ios::beg);
                flux >> width_;
                flux.seekg(1,std::ios::cur);
                flux >> height_;
                flux.ignore();
                flux.clear();
                std::string line;
                int index = 0;
                uchar r,g,b;
                while(getline(flux,line))
                {
                    if(index == 0){r = (uchar)std::stoi(line); index++;} 
                    else if(index == 1){g = (uchar)std::stoi(line); index++;}
                    else {b = (uchar)std::stoi(line); pixel_.emplace_back(Color(r,g,b)); index = 0;}
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cout << e.what();
            std::exit(0);
        }
    }
    std::ostream& operator<<(std::ostream& os,const Image& img)
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
    std::string imageName(std::string path) 
    {
        std::string name;
        if(auto pos_point = path.find_last_of('.'); pos_point!=path.npos) 
        {
            path.resize(pos_point);
        }
        if(auto pos_slash = path.find_last_of('/'); pos_slash!=path.npos) 
        {
            name = path.substr(pos_slash+1);
        }
        return name;
    }
    void save(const Image& img)
    {
        try
        {
            if(size(img) == 0) throw std::runtime_error("Image don't have any size !\n");
            std::ofstream flux("data/"+img.getName()+".ppm");
            if(!flux) throw std::runtime_error("Can't create file\n");
            else
            {
                flux << "P3\n";
                flux << img.getWidth(); 
                flux << " ";
                flux << img.getHeight();
                flux << "\n";
                for(int pixel = 0; pixel < size(img); pixel++)
                {
                    for(int color = 0; color < 3; color++) {flux << std::to_string(img[pixel][color]); flux << "\n";}
                }
            }
        }
        catch(std::runtime_error& e)
        {
            std::cout << e.what();
            std::exit(0);
        }

    }
    Image grey(const Image& img)
    {
        Image greyImg{"grey "+img.getName(),img.getWidth(),img.getHeight()};

        for(int i = 0; i < size(greyImg); i++) 
        {
            const_cast<Color&>(greyImg[i]) = grey(Color(img[i]));
        }
        return greyImg; 
    }
} // namespace s5loo
