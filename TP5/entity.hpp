#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "color.hpp"
#include "shape.hpp"

namespace s5loo {

class Entity
{
private:
    
    std::unique_ptr<Shape> shape_;

    Color color_;

    double fwidth_, fheight_,
           x_, y_,
           sx_, sy_,
           radius_,
           angle_, angularSpeed_;

    

    void angle(double value) 
    {
        if(angle_ <= -180) angle_ += 360;
        else if(angle_ >= 180) angle_ -= 360;
        angle_+= value;
    }

public:

    Entity() = default;
    Entity(const Entity&) = default;
    Entity& operator=(const Entity&) = delete;

    Entity(Entity &&) = default;
    Entity& operator=(Entity &&) = default;

    virtual ~Entity() = default;

    Entity(std::unique_ptr<Shape> shape,
           Color color,
           double fwidth, double fheight,
           double x, double y,
           double sx, double sy,
           double radius,
           double angle = 0.0, double angleSpeed = 0.0)
    : shape_(std::move(shape)),
      color_(std::move(color)),
      fwidth_(fwidth), fheight_(fheight),
      x_(x), y_(y), 
      sx_(sx), sy_(sy),
      radius_(radius),
      angle_(angle), angularSpeed_(angleSpeed)
    {};

    const Color& color() const {return color_;}
    double radius() const {return radius_;}
    auto position() const {return std::make_tuple(x_,y_);}
    auto speed() const {return std::make_tuple(sx_,sy_);}
    auto dimWin() const {return std::make_tuple(fwidth_,fheight_);}
    double angle() const {return angle_;}
    double angularSpeed() const {return angularSpeed_;}
    void draw(sf::RenderWindow& window) {shape_->draw(*this,window);};
};
}

#endif // ENTITY_HPP