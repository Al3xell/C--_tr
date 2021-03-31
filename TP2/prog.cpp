#include <iostream>

#include "color.hpp"
#include "image.hpp"

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
    std::cout << "Noir : " << (int)noir[0] << "\n";
}

void test_simple_image()
{
    s5loo::Image img1{"random", 5, 3};
    s5loo::Image img2{"black", 3, 4, false};
    std::cout << img1 << "\n";
    std::cout << img2;
    //std::cout << img1[s5loo::size(img1)+1];
}

int main(int argc, char const *argv[])
{
    try
    {
        if(argc == 1)
        {
            throw std::runtime_error{"To run this application, specify the name of the test you want to try. For example:\n./prog color\npossible tests are: color, simple_image"};
        }
        else
        {
            std::string str1 = argv[1];
            if(str1.compare("color") == 0) test_color();
            else if(str1.compare("simple_image") == 0) test_simple_image();
            else throw std::runtime_error{"To run this application, specify the name of the test you want to try. For example:\n./prog color\npossible tests are: color, simple_image"};
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
