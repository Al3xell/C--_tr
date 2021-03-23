#include "module.hpp"

int 
main(int argc, char const *argv[])
{
    s5poo::Sensor sensor("sensor", 5, 10);
    sensor.add(8);
    sensor.add(6);
    std::cout <<"value : "<< sensor.get_value(-1) << '\n';
    std::cout <<"value : "<< sensor.get_value(5) << '\n';
    std::cout <<"value : "<< sensor.get_value(1) << '\n';
    return 0;
}
 