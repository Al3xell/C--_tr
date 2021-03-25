#ifndef MODULEVECTOR_HPP
#define MODULEVECTOR_HPP

#include <vector>
#include <tuple>

namespace s5loo
{
    using intvec = std::vector<int>;

    intvec makeVector(int count,
                      int nMin = 10,
                      int nMax = 100);   
    
    void printVector(intvec vector);

    int numEven(const intvec vector);

    std::tuple<double, double, double> dataVector(const intvec vector);
}

#endif // !MODULEVECTOR_HPP