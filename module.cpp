#include <string>
#include <vector> 
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

    }

    void Sensor::add(double value)
    {
        if(value < min_) values_.emplace_back(min_);
        else if(value > max_) values_.emplace_back(max_);
        else values_.emplace_back(value);
    }
    
} // namespace s5poo
