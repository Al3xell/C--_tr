#include <string>
#include <vector> 
#include <iostream>
#include "module.hpp"

namespace s5poo
{
    Sensor::Sensor(std::string name,
               double min,
               double max)
    : name_(std::move(name))
    , min_(min)
    , max_(max)
    , values_{}
    {
        std::cout << name_ << " has been created !\n";
    }

    void Sensor::add(double value)
    {
        if(value < min_) values_.emplace_back(min_);
        else if(value > max_) values_.emplace_back(max_);
        else values_.emplace_back(value);
        std::cout << value << " added to the sensor !\n";

    }
    
} // namespace s5poo
