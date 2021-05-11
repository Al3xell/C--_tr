#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 

#include <tuple>
#include <algorithm>
#include <cmath>

#include "color.hpp"

namespace s5loo 
{
    class Rectangle
    {
    private:
        double fwidth_, fheight_, 
               width_, height_,
               x_, y_, 
               sx_, sy_, 
               angle_, angularSpeed_;

        Color color_;

        void angle(double value) 
        {
            if(angle_ <= -180) angle_ += 360;
            else if(angle_ >= 180) angle_ -= 360;
            angle_+= value;
        }

    public:
        
        Rectangle() = default;

        Rectangle(const Rectangle&) = default;
        Rectangle& operator=(const Rectangle&) = delete;

        Rectangle(Rectangle &&) = default;
        Rectangle& operator=(Rectangle &&) = default;

        ~Rectangle() = default;

        Rectangle(double fwidth,double fheight,
                  double width, double height,
                  double x, double y,
                  double sx, double sy,
                  Color color,
                  double angularSpeed = 0.0)
        : fwidth_(fwidth), fheight_(fheight),
          width_(width), height_(height),
          x_{std::clamp(x,width/2,fwidth-width/2)}, y_{std::clamp(y,height/2,fheight-height/2)}, 
          sx_(sx), sy_(sy), 
          angle_(0.0), angularSpeed_(angularSpeed),
          color_(std::move(color))
        {};

        const Color& color() const {return color_;}
        double angle() const {return angle_;}
        auto position() const {return std::make_tuple(x_,y_);}
        auto size() const {return std::make_tuple(width_,height_);}
        void move(double fwidth, double fheight, double dt);
    };

    inline void draw(const Rectangle& rectangle, sf::RenderWindow& window)
    {
        sf::RectangleShape s{sf::Vector2f{(float)std::get<0>(rectangle.size()), (float)std::get<1>(rectangle.size())}};
        auto color = rectangle.color();
        s.setFillColor(sf::Color{color[0], color[1], color[2]});
        s.setOrigin(float(std::get<0>(rectangle.size())*0.5), float(std::get<1>(rectangle.size())*0.5));
        s.setPosition(float(std::get<0>(rectangle.position())),float(std::get<1>(rectangle.position())));
        s.setRotation(float(rectangle.angle()));
        window.draw(s);  
    }

    inline void Rectangle::move(double fwidth, double fheight, double dt)
    {
        x_+= dt*sx_;
        y_+= dt*sy_;
        angle(dt*angularSpeed_);
        double radius = sqrt((std::get<0>(size())/2*std::get<0>(size())/2)+(std::get<1>(size())/2*std::get<1>(size())/2));
        if(x_ < radius) {x_= radius; sx_ *= -1;}
        else if(x_> fwidth-radius) {x_=fwidth-radius; sx_*= -1;}
        
        if(y_< radius) {y_= radius; sy_ *= -1;}
        else if(y_> fheight-radius) {y_= fheight-radius; sy_*= -1;}
        

    }
    
}
#endif // !RECTANGLE_HPP