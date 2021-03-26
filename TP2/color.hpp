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
        Color() : red_(0), green_(0), blue_(0) {};
        uchar& operator[](int i) const;
        uchar& operator[](int i);
    };

    inline uchar& Color::operator[](int i) 
    {
        try
        {
            if(i==0) return red_;
            else if(i==1) return green_;
            else if(i==2) return blue_;
            else throw std::out_of_range{"Index needs to be between 0 and 2"};
        }
        catch(std::exception &e)
        {
            std::cout << e.what();
        }
    }
    
    inline std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        return os << "(" << (int)color.red_ << ", " << (int)color.green_ << ", " << (int)color.blue_ << ")\n";
    }

    inline Color grey(const Color& color)
    {
        uchar average = (uchar)(((int)color.red_+(int)color.green_+(int)color.blue_)/3);
        return Color(average,average,average);
    }
} // namespace s5loo

#endif // !COLOR_HPP
