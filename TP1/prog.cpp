#include <iostream>
#include <string>
#include <array>

#include "moduleArray.hpp"

void test_array()
{
    std::cout << "~~~~~entering " << __func__ << "()~~~~~\n\n";
    s5loo::str15 array;
    s5loo::fillArray(array);
    s5loo::printArray(array);
    std::cout << "isPalindrome : ";
    for(int i=0; i < (int)array.size(); i++)
    {
        std::cout << "{" << array[i] << " : " << s5loo::isPalindrome(array[i]) << "}";
    }
    std::cout << "\n\n";
    std::cout << "~~~~~leaving " << __func__ << "()~~~~~\n";
}

int main(int argc, const char** argv) 
{
    test_array();
    return 0;
}