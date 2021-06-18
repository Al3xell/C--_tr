#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#include <random>

int main() {
  s5loo::Window win{"Rectangles and Circles", 800,600};
  auto [width, height] = win.size();

  std::default_random_engine rndGen{std::random_device{}()};
  std::uniform_int_distribution<short> colorDistr{0, 255};
  std::uniform_real_distribution<double> speedDistr{-200, 200};
  std::uniform_real_distribution<double> dimDistr{10, 60};
  std::uniform_real_distribution<double> xposDistr{0, width};
  std::uniform_real_distribution<double> yposDistr{0, height};
  std::uniform_real_distribution<double> angularDistr{-200, 200};
  std::uniform_real_distribution<double> objectNumber{10, 20};
  
  for (int i = 0; i < objectNumber(rndGen); i++)
  {
    win.add(s5loo::Entity(std::make_unique<s5loo::Circle>(),
                          s5loo::Color{(s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen)},
                          width, height, 
                          std::clamp(xposDistr(rndGen),radius,fwidth-radius),std::clamp(y,radius,fheight-radius), yposDistr(rndGen), 
                          speedDistr(rndGen), speedDistr(rndGen), 
                          dimDistr(rndGen)));  
  }
  for (int i = 0; i < objectNumber(rndGen); i++)
  {
    win.add(s5loo::Entity(std::make_unique<s5loo::Rectangle> (dimDistr(rndGen), dimDistr(rndGen)),
                          s5loo::Color{(s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen)},
                          width, height, 
                          xposDistr(rndGen), yposDistr(rndGen), 
                          speedDistr(rndGen), speedDistr(rndGen), 
                          dimDistr(rndGen),
                          angularDistr(rndGen)));
    
  }

  win.display();

  return 0;
}
