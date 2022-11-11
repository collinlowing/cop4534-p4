//
// Created by cel on 11/7/22.
//

#include "OptimalPacker.hpp"
#include "FileParser.hpp"
#include "PermutationGenerator.hpp"

double *OptimalPacker::getOptimalBinStack(std::string fileName) {
    // use just two simple arrays and not object pointers. Try and fill in each bin iteratively but skip to the next bin when it is full.
    // get items from file
    std::vector<double> itemsVector = FileParser::getItemsFromFile(fileName);
    numberOfItems = (int) itemsVector.at(0);
    lowestNumberOfBins = numberOfItems;
    int* indexes = new int[numberOfItems]();
    double* items = new double[numberOfItems]();
    double* bin = new double[numberOfItems]();
    optimalBin = new double[numberOfItems]();
    double binTotal = 0;

    // initialize the index of items to add to stack of bins
    // skipping 0 because of permutationGenerator may not function properly
    // subtract 1 from all indexes used from array
    for(int i = 1; i < numberOfItems + 1; i++) {
        indexes[i - 1] = i;
    }

    // copy vector to array for faster accessing
    for(int i = 1; i < numberOfItems + 1; i++) {
        items[i - 1] = itemsVector[i];
        std::cout << items[i - 1] << " ";
    }

    // initialize permutation generator
    PermutationGenerator pg(indexes, numberOfItems);

    // get number of permutations
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numberOfItems);

    // iterate through all possible permutations
    for(int permutationCount = 0; permutationCount < numOfPermutations; permutationCount++) {
        int numberOfBins = 1;
        for(int itemIndex = 0; itemIndex < numberOfItems; itemIndex++) {
            if(binTotal >= 1.0) {
                numberOfBins++;
                binTotal = 0;
            }
            binTotal += items[indexes[itemIndex] - 1];
            double item = items[indexes[itemIndex] - 1];
            bin[itemIndex] = item;
        }
        if(numberOfBins < lowestNumberOfBins) {
            lowestNumberOfBins = numberOfBins;
            std::cout << "optimal" << std::endl;
            for(int i = 0; i < numberOfItems; i++) {
                std::cout << bin[i] << " ";
            }
            std::cout << std::endl;
            for(int i = 0; i < numberOfItems; i++) {
                optimalBin[i] = bin[i];
            }
        }
        indexes = pg.getNextPermutation();
    }

    //delete[] indexes;
    delete[] items;
    delete[] bin;

    return optimalBin;
}

int OptimalPacker::getLowestNumberOfBins() {
    return lowestNumberOfBins + 1;
}

void OptimalPacker::print() {
    /*for(int i = 0; i < numberOfItems; i++) {
        std::cout << optimalBin[i] << " ";
    }
    std::cout << std::endl;*/

    double binTotal = 0;
    bool newLine = false;
    int binCount = 0;
    for(int i = 0; i < numberOfItems; i++) {
        binTotal += optimalBin[i];
        if(binTotal >= 1) {
            std::cout << std::endl;
            std::cout << "b" << binCount << ": ";
            binTotal = 0;
            binCount++;
        }
        if(binCount == 0) {
            std::cout << "b" << binCount << ": ";
            binCount++;
        }
        if(optimalBin[i + 1] > 0 && optimalBin[i + 1] + binTotal >= 1) {
            std::cout << optimalBin[i];
        }
        else {
            std::cout << optimalBin[i] << ", ";
        }
        /*if(binTotal <= 0) {
            std::cout << "b" << binCount << ": ";
        }
        binTotal += optimalBin[i];
        if(binTotal > 1) {
            binCount++;
            binTotal = 0;
            std::cout << previousItem << std::endl;
        }
        if(previousItem > 0) {
            std::cout << previousItem << ", ";
        }

        previousItem = optimalBin[i];*/
    }
}
