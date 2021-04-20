#include <iostream>

#include "color.hpp"
#include "image.hpp"

void test_color()
{
    s5loo::Color red{255,0,0};
    s5loo::Color c;
    c[1] = 165;
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

void test_image(std::string path, bool greyBool)
{
    s5loo::Image img;
    if(path.compare("") == 0)
    {  
        std::string name;
        int width, height;
        std::cout << "Insert name : ";
        std::cin >> name;
        do
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Insert width : ";
        }while(!(std::cin >> width));
        do
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Insert height : ";
        }while(!(std::cin >> height));
        std::cout << "\nNew Image created !\n\n";
        img = s5loo::Image(name, width, height);
        s5loo::save(img);
        
        if(greyBool)
        {
            s5loo::Image greyImg = s5loo::grey(img);
            s5loo::save(greyImg);
        }
    }
    else
    {
        img = s5loo::Image(path);
        if(greyBool)
        {
            s5loo::Image greyImg = s5loo::grey(img);
            s5loo::save(greyImg);
        }
    }
    


}
int main(int argc, char const *argv[])
{
    try
    {
        if(argc == 1)
        {
            throw std::runtime_error{"To run this application, specify the name of the test you want to try. For example:\n./prog color\npossible tests are: color, simple_image, image args*, grey args*"};
        }
        else
        {
            std::string str1 = argv[1];
            if(str1.compare("color") == 0) test_color();
            else if(str1.compare("simple_image") == 0) test_simple_image();
            else if(str1.compare("image") == 0)
            {
                if(argc < 3) test_image("",false);
                else test_image(argv[2],false);
            }
            else if(str1.compare("grey") == 0)
            {
                if(argc < 3) test_image("",true);
                else test_image(argv[2],true);
            }
            else throw std::runtime_error{"To run this application, specify the name of the test you want to try. For example:\n./prog color\npossible tests are: color, simple_image, image args*, grey args*"};
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
