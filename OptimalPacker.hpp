//
// Created by cel on 11/7/22.
//

#ifndef COP4534_P4_OPTIMALPACKER_HPP
#define COP4534_P4_OPTIMALPACKER_HPP


#include <string>
#include <float.h>
#include "Bins.hpp"

class OptimalPacker {
private:
    int numberOfItems;
    int lowestNumberOfBins;
    double* optimalBin = nullptr;
    double BIN_MAX = 1.0;
public:
    int getLowestNumberOfBins();

    double* getOptimalBinStack(std::string fileName);

    void print();
};


#endif //COP4534_P4_OPTIMALPACKER_HPP
