#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <random>

namespace s5loo
{
    class Entity;
    class Shape 
    {
    private:


    public:
        Shape() = default;

        Shape(const Shape&) = default;
        Shape& operator=(const Shape&) = delete;

        Shape(Shape &&) = default;
        Shape& operator=(Shape &&) = default;

        virtual ~Shape() = default;

        virtual void draw(Entity &entity, sf::RenderWindow& window) const = 0;

        /*virtual void click(float x, float y, double fwidth, double fheight) final
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
        }*/
    };
    
    
} // namespace s5loo

#endif // !SHAPE_HPP