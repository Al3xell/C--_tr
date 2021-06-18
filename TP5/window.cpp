#include <iostream>
#include <chrono>

#include "window.hpp"


namespace s5loo {

/* non member functions definition */

double getTime() {
  const auto now{std::chrono::system_clock::now().time_since_epoch()};
  return 1e-3*double(std::chrono::duration_cast
                   <std::chrono::milliseconds>(now).count());
}

/* member functions definition */

Window::Window(std::string n, double w, double h) : name_{std::move(n)}, width_{w}, height_{h}, 
                                         win_{sf::VideoMode{(unsigned int)width_, (unsigned int)height_}, name_.data()},
                                         entities_{}
{ }

void Window::display() {  
  
  double lastTime=getTime();
  while (win_.isOpen())
  {
    const double dt=getTime()-lastTime;
    lastTime+=dt;
    const double step=1.0/30.0; // target 30 FPS
    if (dt<step) {
      sf::sleep(sf::seconds(float(step-dt)));
    }

    win_.clear(sf::Color(100, 100, 100));
    drawAll_();
    moveAll_(width_, height_, dt);

    win_.display();

    sf::Event event;
    while(win_.pollEvent(event)) 
    {
      switch (event.type) 
      {
        case sf::Event::Closed :
             win_.close();
             return;
        case sf::Event::MouseButtonPressed:
             if (event.mouseButton.button ==sf::Mouse::Left) {  
               const auto coord=win_.mapPixelToCoords({event.mouseButton.x,
                                                    event.mouseButton.y});
               for(auto& elem : entities_)
               {
                 //elem->click(coord.x, coord.y, width_, height_);
               }
               std::cout << "left_button on (" << coord.x << "," << coord.y << ")\n";
             }
             break;
        case sf::Event::KeyPressed:
             if(event.key.code == sf::Keyboard::Escape) {
               win_.close();
             }
             if(event.key.code == sf::Keyboard::Left) {
                std::cout<< "LEFT\n";
	         }
	         if(event.key.code == sf::Keyboard::Right) {
                std::cout<< "RIGHT\n";
	         } 
	         if(event.key.code == sf::Keyboard::Up) {
                std::cout<< "UP\n";
	         }
	         if(event.key.code == sf::Keyboard::Down) {
                std::cout<< "DOWN\n";
	         }
	         if(event.key.code == sf::Keyboard::A) {
                std::cout<< "A\n";
	         }
             break;
        default:
             break;
      }
    }
  }
}

void Window::add(Entity entity){entities_.emplace_back(std::move(entity));}

void Window::drawAll_() 
  {
    for(auto& elem : entities_) {elem.draw(win_);}
  }
void Window::moveAll_(double width,double height, double dt)
  {
    //for(auto& elem : entities_) {elem.move();}
  }

}  // namespace s5loo
