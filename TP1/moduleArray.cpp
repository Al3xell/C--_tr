#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <random>

#include "moduleArray.hpp"



namespace s5loo
{
    using str15 = std::array<std::string,15>;
    void fillArray(str15 &array)
    {
        std::default_random_engine rndGen{std::random_device{}()};
        std::uniform_int_distribution<int> lengthDistrib{3, 6};
        std::uniform_int_distribution<int> charDistrib{'a', 'e'};
        for(int i=0; i < (int)array.size(); i++)
        {
            int x = lengthDistrib(rndGen);
            for(int j=0; j < x; j++) array[i].push_back((char)charDistrib(rndGen));
        }
        
    }

    void printArray(const str15 &array)
    {
        std::cout << "\nvalue in array : ";
        for(int i=0; i < (int)array.size(); i++) std::cout << "{" << array[i] << "} ";
        std::cout << '\n';
    }

    bool isPalindrome(const std::string word)
    {
        std::string rword = word;
        std::reverse(rword.begin(),rword.end());
        if(word == rword) return true;
        else return false;
        
    }
} //namespace s5loo