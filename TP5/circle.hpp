#ifndef CIRCLE_HPP
#define CIRCLE_HPP 

#include <tuple>
#include <algorithm>

#include "entity.hpp"

namespace s5loo 
{
    class Circle final : public Shape
    {
    private:

    public:

        Circle() = default;

        ~Circle() = default;
        
        void draw(Entity &entity, sf::RenderWindow& window) const override;

    };

    inline void Circle::draw(Entity &entity, sf::RenderWindow& window) const
    {

        sf::CircleShape shape{float(entity.radius())};
        auto clr = entity.color();
        shape.setFillColor(sf::Color{clr[0], clr[1], clr[2]});
        shape.setOrigin(float(entity.radius()), float(entity.radius()));
        shape.setPosition((float)std::get<0>(entity.position()),(float)std::get<1>(entity.position()));
        window.draw(shape); 
    }
    
}
#endif // !CIRCLE_HPP
