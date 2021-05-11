#include "window.hpp"

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
    win.add(std::make_unique<s5loo::Circle>(width, height, 
                    xposDistr(rndGen), yposDistr(rndGen), 
                    speedDistr(rndGen), speedDistr(rndGen), 
                    dimDistr(rndGen), 
                    s5loo::Color{(s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen)}));
  
  }
  for (int i = 0; i < objectNumber(rndGen); i++)
  {
    win.add(std::make_unique<s5loo::Rectangle>(width, height, 
                                                dimDistr(rndGen), dimDistr(rndGen),
                                                xposDistr(rndGen), yposDistr(rndGen), 
                                                speedDistr(rndGen), speedDistr(rndGen), 
                                                s5loo::Color{(s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen), (s5loo::uchar)colorDistr(rndGen)},
                                                angularDistr(rndGen)));
    
  }

  win.display();

  return 0;
}
