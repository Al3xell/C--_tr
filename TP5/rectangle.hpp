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
    
        double rwidth_, rheight_;

    public:
    
        Rectangle(double rwidth, double rheight)
        : rwidth_(rwidth), rheight_(rheight)
        {};

        ~Rectangle() = default;

        auto size() const {return std::make_tuple(rwidth_,rheight_);}
/*
        void move(double fwidth, double fheight, double dt) override final
        {
            Shape::move(fwidth,fheight,dt);
            angle(dt*angularSpeed_);
        }*/
        void draw(Entity &entity, sf::RenderWindow& window) const override final;
        //void do_click(float x, float y, double fwidth, double fheight) override final;
    };

    inline void Rectangle::draw(Entity &entity, sf::RenderWindow& window) const
    {
        sf::RectangleShape s{sf::Vector2f{(float)std::get<0>(size()), (float)std::get<1>(size())}};
        auto clr = entity.color();
        s.setFillColor(sf::Color{clr[0], clr[1], clr[2]});
        s.setOrigin(float(std::get<0>(size())*0.5), float(std::get<1>(size())*0.5));
        s.setPosition(float(std::get<0>(entity.position())),float(std::get<1>(entity.position())));
        s.setRotation(float(entity.angle()));
        window.draw(s);  
    }
    /*
    inline void Rectangle::do_click(float x, float y, double fwidth, double fheight)
    {
        std::default_random_engine rndGen{std::random_device{}()};
        std::uniform_real_distribution<double> angularDistr{-200, 200};
        
        Shape::do_click(x, y, fwidth, fheight);
        angularSpeed_ = angularDistr(rndGen);
    }*/
}
#endif // !RECTANGLE_HPP