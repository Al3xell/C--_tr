#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdexcept>
#include <iostream>

namespace s5loo
{
    using uchar = unsigned char ;

    struct Color 
    {
        uchar red_, green_, blue_;

        Color(uchar red, uchar green, uchar blue) : red_(red), green_(green), blue_(blue) {}
        Color() : red_(0), green_(0), blue_(0) {}
        uchar& Color::operator[](int i, uchar arg);
        const uchar& Color::operator[](int i);
    };

    uchar& Color::operator[](int i, uchar arg)
    {
        try
        {
            if(i==0) arg = Color::red_;
            else if(i==1) arg = Color::green_;
            else if(i==2) arg = Color::blue_;
            else throw std::out_of_range{"Index needs to be between 0 and 2"};
        }
        catch(std::exception &e)
        {
            std::cout << e.what();
        }
    }

    inline const uchar& Color::operator[](int i) 
    {
        try
        {
            if(i==0) return Color::red_;
            else if(i==1) return Color::green_;
            else if(i==2) return Color::blue_;
            else throw std::out_of_range{"Index needs to be between 0 and 2"};
        }
        catch(std::exception &e)
        {
            std::cout << e.what();
        }
    }
} // namespace s5loo

#endif // !COLOR_HPP
