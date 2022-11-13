/***************************************************************
  Student Name: Collin Lowing
  File Name: OptimalPacker.cpp
  Project 4

  Tries every combination to get the best packing of bins
***************************************************************/

#include "OptimalPacker.hpp"
#include "FileParser.hpp"
#include "PermutationGenerator.hpp"

double *OptimalPacker::getOptimalBinStack(std::string fileName) {
    // use just two simple arrays and not object pointers. Try and fill in each bin iteratively but skip to the next bin when it is full.
    // get items from file
    std::vector<double> itemsVector = FileParser::getItemsFromFile(fileName);
    numberOfItems = (int) itemsVector.at(0);
    lowestNumberOfBins = numberOfItems;
    indexesP = new int[numberOfItems]();
    double *items = new double[numberOfItems]();
    double *bin = new double[numberOfItems]();
    optimalBin = new double[numberOfItems]();
    double binTotal = 0;

    // initialize the index of items to add to stack of bins
    // skipping 0 because of permutationGenerator may not function properly
    // subtract 1 from all indexes used from array
    for (int i = 1; i < numberOfItems + 1; i++) {
        indexesP[i - 1] = i;
    }

    // copy vector to array for faster accessing
    for (int i = 1; i < numberOfItems + 1; i++) {
        items[i - 1] = itemsVector[i];
    }

    // initialize permutation generator
    PermutationGenerator pg(indexesP, numberOfItems);

    // get number of permutations
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numberOfItems);

    // iterate through all possible permutations
    for (int permutationCount = 0; permutationCount < numOfPermutations; permutationCount++) {
        int numberOfBins = 1;
        indexesP = pg.getNextPermutation();
        double item;
        for (int itemIndex = 0; itemIndex < numberOfItems; itemIndex++) {
            item = items[indexesP[itemIndex] - 1];
            // if bigger than maximum
            if ((binTotal + item - BIN_MAX) >= DBL_MIN) {
                numberOfBins++;
                binTotal = item;
            } else {
                binTotal += item;
            }
            bin[itemIndex] = item;
        }
        if (numberOfBins < lowestNumberOfBins) {
            // set lowest number of bins to number of bins
            lowestNumberOfBins = numberOfBins;
            // copy to optimalBin
            for (int i = 0; i < numberOfItems; i++) {
                optimalBin[i] = bin[i];
            }
        }
    }

    //delete[] indexes;
    delete[] items;
    delete[] bin;

    return optimalBin;
}

int OptimalPacker::getLowestNumberOfBins() {
    return lowestNumberOfBins;
}

void OptimalPacker::print() {
    double binTotal = 0;
    int binCount = 0;

    std::cout << "b" << binCount << ": ";
    binCount++;

    double nextItem;

    for (int i = 0; i < numberOfItems; i++) {
        double item = optimalBin[i];
        binTotal += item;
        if (i + 1 >= numberOfItems) {
            std::cout << item << std::endl;
            break;
        } else {
            nextItem = optimalBin[i + 1];
        }
        if ((binTotal + nextItem - BIN_MAX) >= DBL_MIN) {
            std::cout << item << std::endl;
            // print new bin
            std::cout << "b" << binCount << ": ";
            binCount++;
            binTotal = 0;
        } else {
            std::cout << item << ", ";
        }

    }
}

OptimalPacker::~OptimalPacker() {
    delete[] optimalBin;
    // When uncommented, throws an error.
    // Although without deleting indexes pointer, there is a memory leak.
    //delete [] indexesP;
}
