#ifndef CIRCLE_HPP
#define CIRCLE_HPP 

#include <tuple>
#include <algorithm>

#include "shape.hpp"

namespace s5loo 
{
    class Circle final : public Shape
    {
    private:

    public:

        ~Circle() = default;

        Circle(double fwidth,double fheight,
               double x, double y,
               double sx, double sy,
               double radius, 
               Color color)
        : Shape(fwidth,fheight,
                std::clamp(x,radius,fwidth-radius),std::clamp(y,radius,fheight-radius),
                sx,sy,
                radius,
                color)
        {};
        void draw(sf::RenderWindow& window) const override;

    };

    inline void Circle::draw(sf::RenderWindow& window) const
    {

        sf::CircleShape shape{float(radius())};
        auto clr = color();
        shape.setFillColor(sf::Color{clr[0], clr[1], clr[2]});
        shape.setOrigin(float(radius()), float(radius()));
        shape.setPosition((float)std::get<0>(position()),(float)std::get<1>(position()));
        window.draw(shape); 
    }
    
}
#endif // !CIRCLE_HPP
