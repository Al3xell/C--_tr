#ifndef S5LOO_WINDOW_HPP
#define S5LOO_WINDOW_HPP 

#include <vector>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <memory>

#include "entity.hpp"

namespace s5loo {

class Window {
  public :
  Window(std::string n="Window", double w=700, double h=500);
    
  /* Special functions */
  //disable copy and move
  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(Window&&) = delete;

  //default destruction is suitable
  virtual ~Window() = default;
  /**/

  std::tuple<double,double> size() const;

  void display();

  void add(Entity entity);
  void drawAll_();
  void moveAll_(double width,double height, double dt);

  private :
  std::string name_;
  double width_, height_;
  sf::RenderWindow win_;
  std::vector<Entity> entities_;
};  // class Window

/* inline member functions */

inline
std::tuple<double,double> Window::size() const { return {width_, height_}; }

/* non member functions declaration */

double // seconds since 1970/01/01 00:00:00 UTC (avec des décimales allant jusqu'aux microsecondes)
getTime();


}  // namespace s5loo

#endif
