#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 

#include <tuple>
#include <algorithm>
#include <cmath>

#include "shape.hpp"

namespace s5loo 
{
    class Rectangle final : public Shape
    {
    private:
        double rwidth_, rheight_, 
               angle_, angularSpeed_;

        void angle(double value) 
        {
            if(angle_ <= -180) angle_ += 360;
            else if(angle_ >= 180) angle_ -= 360;
            angle_+= value;
        }

    public:
        
        ~Rectangle() = default;

        Rectangle(double fwidth,double fheight,
                  double rwidth, double rheight,
                  double x, double y,
                  double sx, double sy,
                  Color color,
                  double angularSpeed = 0.0)
        : Shape(fwidth,fheight,
                std::clamp(x,rwidth/2,fwidth-rwidth/2),std::clamp(y,rheight/2,fheight-rheight/2),
                sx,sy,
                sqrt((rwidth/2*rwidth/2)+(rheight/2*rheight/2)),
                color),
          rwidth_(rwidth), rheight_(rheight), 
          angle_(0.0), angularSpeed_(angularSpeed)
        {};

        double angle() const {return angle_;}
        auto size() const {return std::make_tuple(rwidth_,rheight_);}

        void move(double fwidth, double fheight, double dt) override final
        {
            Shape::move(fwidth,fheight,dt);
            angle(dt*angularSpeed_);
        }
        void draw(sf::RenderWindow& window) const override final;
        void do_click(float x, float y, double fwidth, double fheight) override final;
    };

    inline void Rectangle::draw(sf::RenderWindow& window) const
    {
        sf::RectangleShape s{sf::Vector2f{(float)std::get<0>(size()), (float)std::get<1>(size())}};
        auto clr = color();
        s.setFillColor(sf::Color{clr[0], clr[1], clr[2]});
        s.setOrigin(float(std::get<0>(size())*0.5), float(std::get<1>(size())*0.5));
        s.setPosition(float(std::get<0>(position())),float(std::get<1>(position())));
        s.setRotation(float(angle()));
        window.draw(s);  
    }
    
    inline void Rectangle::do_click(float x, float y, double fwidth, double fheight)
    {
        std::default_random_engine rndGen{std::random_device{}()};
        std::uniform_real_distribution<double> angularDistr{-200, 200};
        
        angularSpeed_ = angularDistr(rndGen);
    }
}
#endif // !RECTANGLE_HPP