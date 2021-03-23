#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include <vector> 
#include <tuple>
#include <iostream>

namespace s5poo
{
    class Sensor
    {
        private :
        std::string name_;
        double min_, max_;
        std::vector<double> values_;

        public :
        Sensor(std::string name,
               double min,
               double max);

        Sensor(std::string name, double max)
        : Sensor{std::move(name), 0, max} {}

        void add(double value);

        const std::string& name()
        {
            return name_;
        }

        int size_vector()
        {
            return (int)values_.size();
        }
        
        const std::tuple<double*,double*> interval()
        {
           return std::make_tuple(&min_,&max_);
        }

        const auto get_value(int index)
        {
            try 
            {
            
                if(index < 0)
                {
                    throw "index too low ! ";
                }
                else if(index > (int)values_.size())
                {
                    throw "index too high ! ";
                }
                else
                {
                    return values_[index];
                }
            }
            
            catch (char const* e)
            {
                std::cout << e;
                return 0.0;
            }
        }
    };
} // namespace s5poo


#endif // MODULE_HPP
