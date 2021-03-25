#include <iostream>
#include <vector>
#include <random>
#include <exception>
#include <algorithm>
#include <cmath>

#include "moduleVector.hpp"

namespace s5loo
{
    using intvec = std::vector<int>;

    intvec makeVector(int count,
                      int nMin,
                      int nMax)
    {
        std::default_random_engine rndGen{std::random_device{}()};
        std::uniform_int_distribution<int> lengthDistrib{nMin, nMax};
        intvec vector;

        for(int i = 0; i < count; i++) vector.emplace_back(lengthDistrib(rndGen));
        return vector;
    }

    void printVector(intvec vector)
    {
        std::cout << "\nvalue in vector : ";
        for(int i=0; i < (int)vector.size(); i++) std::cout << "{" << vector[i] << "} ";
        std::cout << '\n';
    }

    int numEven(const intvec vector)
    {
        int numEven = 0;
        for(int i = 0; i < (int)vector.size(); i++) if(vector[i]%2==0) numEven += 1;
        return numEven;
    }
    std::tuple<double, double, double> dataVector(const intvec vector)
    {
        try
        {
            if((int)vector.size()==0) throw std::invalid_argument{"vector size is NULL !"};

            double sumAverage = 0;
            for(int i = 0; i < (int)vector.size(); i++) sumAverage += vector[i];
            double average = sumAverage/(int)vector.size();

            double sumStdDeviation = 0;
            for(int i = 0; i < (int)vector.size(); i++) sumStdDeviation += pow((vector[i]-average),2);
            double stdDeviation = std::sqrt(sumStdDeviation/(double)vector.size());

            intvec sortVector = vector;
            std::sort(sortVector.begin(), sortVector.end());

            double median = 0;
            if((int)sortVector.size()%2==1) median = sortVector[int((int)sortVector.size()/2)];
            else if((int)sortVector.size()%2==0) median = (sortVector[(int)sortVector.size()/2-1]+sortVector[(int)sortVector.size()/2])/2;
            else throw std::runtime_error{"Unexpected Error !"};
            return std::make_tuple(std::move(average), std::move(stdDeviation), std::move(median));

        }
        catch(const std::exception &e)
        {
            std::cout << "getting data fail :" << e.what() << std::endl;
            std::cout << "\n~~~~~ leaving " << __func__ << "() ~~~~~\n";
            std::exit(0);
        }
        

    }
}