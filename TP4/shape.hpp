#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include <random>

namespace s5loo
{
    class Shape
    {
    private:

        double fwidth_, fheight_,
               x_, y_,
               sx_, sy_,
               radius_;

        Color color_;

    public:
        Shape() = default;

        Shape(const Shape&) = default;
        Shape& operator=(const Shape&) = delete;

        Shape(Shape &&) = default;
        Shape& operator=(Shape &&) = default;

        virtual ~Shape() = default;

        Shape(double fwidth, double fheight,
              double x, double y,
              double sx, double sy,
              double radius,
              Color color)
        : fwidth_(fwidth), fheight_(fheight),
          x_(x), y_(y), 
          sx_(sx), sy_(sy),
          radius_(radius),
          color_(std::move(color))
        {};

        const Color& color() const {return color_;}
        double radius() const {return radius_;}
        auto position() const {return std::make_tuple(x_,y_);}
        virtual void draw(sf::RenderWindow& window) const = 0;
        virtual void click(float x, float y, double fwidth, double fheight) final
        {
            double dx = x-x_;
            double dy = y-y_;

            if(dx*dx+dy*dy<=radius()*radius())
            {
                do_click(x,y,fwidth,fheight);
            }
        }

        virtual void do_click(float x, float y, double fwidth, double fheight)
        {
            std::default_random_engine rndGen{std::random_device{}()};
            std::uniform_real_distribution<double> speedDistr{0, 200};

            sx_ = speedDistr(rndGen);
            sy_ = speedDistr(rndGen);

            if(x_> fwidth/2 && sx_> 0) sx_*=-1;
            else if(x_< fwidth/2 && sx_< 0) sx_*=-1;
            if(y > fheight/2 && sy_> 0) sy_*=-1;
            else if(y < fheight/2 && sy_< 0) sy_*=-1;
        }


        virtual void move(double fwidth, double fheight, double dt)
        {
            x_+= dt*sx_;
            y_+= dt*sy_;
            if(x_<radius()) {x_=radius(); sx_ *= -1;}
            else if(x_>fwidth-radius()) {x_=fwidth-radius(); sx_*= -1;}
            
            if(y_<radius()) {y_=radius(); sy_ *= -1;}
            else if(y_>fheight-radius()) {y_=fheight-radius(); sy_*= -1;}
        }
    };
    
    
} // namespace s5loo

#endif // !SHAPE_HPP