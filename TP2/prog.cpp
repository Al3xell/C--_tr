#include <iostream>

#include "color.hpp"

void test_color()
{
    s5loo::Color red{255,0,0};
    s5loo::Color c;
    c.green_ = 165;
    s5loo::Color g = grey(red);
    const s5loo::Color noir;
    std::cout << "Red : " << red;
    std::cout << "C : " << c;
    std::cout << "Grey : " << g;
    std::cout << "Noir : " << noir;
}

int main(int argc, char const *argv[])
{
    test_color();
    return 0;
}
