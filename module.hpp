#ifndef MODULE_HPP
#define MODULE_HPP

#include <string>
#include <vector> 

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
        

    };
} // namespace s5poo


#endif // MODULE_HPP
