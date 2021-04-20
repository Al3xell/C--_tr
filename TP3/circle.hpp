#ifndef CIRCLE_HPP
#define CIRCLE_HPP 

#include <tuple>
#include <algorithm>

#include "color.hpp"

namespace s5loo 
{
    class Circle
    {
    private:
        double width_, height_, 
               x_, y_, 
               sx_, sy_, 
               radius_;

        Color color_;

    public:
        
        Circle() = default;

        Circle(const Circle&) = default;
        Circle& operator=(const Circle&) = delete;

        Circle(Circle &&) = default;
        Circle& operator=(Circle &&) = default;

        ~Circle() = default;

        auto position() const {return std::make_tuple(x_,y_);}
        double radius() const {return radius_;}
        const Color& color() const {return color_;}
        void move(double width, double height, double dt);

        Circle(double width,double height,
               double x, double y,
               double sx, double sy,
               double radius, 
               Color color)
        : width_(width), height_(height), 
          x_{std::clamp(x,radius,width-radius)}, y_{std::clamp(y,radius,height-radius)}, 
          sx_(sx), sy_(sy), 
          radius_(radius), color_(std::move(color))
        {};
    };

    inline void draw(const Circle& circle, sf::RenderWindow& window)
    {

        sf::CircleShape shape{(float)circle.radius()};
        auto color = circle.color();
        shape.setFillColor(sf::Color{color[0], color[1], color[2]});
        shape.setOrigin(float(circle.radius()), float(circle.radius()));
        shape.setPosition((float)std::get<0>(circle.position()),(float)std::get<1>(circle.position()));
        window.draw(shape); 
    }

    inline void Circle::move(double width, double height, double dt)
    {
        x_+= dt*sx_;
        y_+= dt*sy_;
        if(x_<radius()) {x_=radius(); sx_ *= -1;}
        else if(x_>width-radius()) {x_=width-radius(); sx_*= -1;}
        
        if(y_<radius()) {y_=radius(); sy_ *= -1;}
        else if(y_>height-radius()) {y_=height-radius(); sy_*= -1;}
        

    }
    
    
}
#endif // !CIRCLE_HPP
