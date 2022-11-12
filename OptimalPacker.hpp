/***************************************************************
  Student Name: Collin Lowing
  File Name: OptimalPacker.hpp
  Project 4

  Tries every combination to get the best packing of bins
***************************************************************/

#ifndef COP4534_P4_OPTIMALPACKER_HPP
#define COP4534_P4_OPTIMALPACKER_HPP


#include <string>
#include <float.h>
#include "Bins.hpp"

class OptimalPacker {
private:
    int numberOfItems;
    int lowestNumberOfBins;
    double *optimalBin = nullptr;
    int *indexesP = nullptr;
    double BIN_MAX = 1.0;
public:
    int getLowestNumberOfBins();

    double *getOptimalBinStack(std::string fileName);

    void print();

    ~OptimalPacker();
};


#endif //COP4534_P4_OPTIMALPACKER_HPP
