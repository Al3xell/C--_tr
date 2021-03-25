#include <iostream>
#include <string>
#include <array>

#include "moduleArray.hpp"
#include "moduleVector.hpp"

void test_array()
{
    std::cout << "\n~~~~~ entering " << __func__ << "() ~~~~~\n";
    s5loo::str15 array;
    s5loo::fillArray(array);
    s5loo::printArray(array);
    std::cout << "isPalindrome : ";
    for(int i=0; i < (int)array.size(); i++)
    {
        std::cout << "{" << array[i] << " : " << s5loo::isPalindrome(array[i]) << "}";
    }
    std::cout << "\n";
    std::cout << "\n~~~~~ leaving " << __func__ << "() ~~~~~\n";
}

void test_vector(const char* arg)
{
    std::cout << "\n~~~~~ entering " << __func__ << "() ~~~~~\n";
    try
    {
        int count = std::stoi(arg);
        s5loo::intvec vector = s5loo::makeVector(count);
        s5loo::printVector(vector);
        std::cout << "number of even : " << s5loo::numEven(vector) << std::endl;
        std::tuple<double, double, double> data = s5loo::dataVector(vector);
        double average = std::get<0>(data), stdDeviation = std::get<1>(data), median = std::get<2>(data);
        std::tie(average,stdDeviation,median);
        std::cout << "\n~~~~~ Data ~~~~~\n";
        std::cout << "\nAverage : " << average << "\nStandard Deviation : " << stdDeviation << "\nMedian : " << median << std::endl;
        std::cout << "\n~~~~~ leaving " << __func__ << "() ~~~~~\n";
    }
    catch(const std::exception& e)
    {
        std::cout << "argument needs to be an integer ! " << '\n';
        std::cout << "\n~~~~~ leaving " << __func__ << "() ~~~~~\n";
        std::exit(0);
    }
    
}

int main(int argc, const char** argv) 
{
    if(argc == 2)
    {
        std::string str1 = argv[1];
        if(str1.compare("array") == 0) test_array();
    }
    else if(argc == 3)
    {
        std::string str1 = argv[1];
        if(str1.compare("vector") == 0) test_vector(argv[2]);
    }
    else
    {
        test_array();
        test_vector("25");
    }
    return 0;
}