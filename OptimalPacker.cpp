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
    int* indexes = new int[numberOfItems]();
    double* items = new double[numberOfItems]();
    double* bin = new double[numberOfItems]();
    double binTotal = 0;

    // initialize the index of items to add to stack of bins
    // skipping 0 because of permutationGenerator may not function properly
    // subtract 1 from all indexes used from array
    for(int i = 1; i <= numberOfItems; i++) {
        indexes[i - 1] = i;
    }

    // removing the number of items in the first index of vector
    itemsVector.erase(itemsVector.begin());
    itemsVector.resize(numberOfItems);

    // copy vector to array for faster accessing
    int counter = 0;
    for(double item: itemsVector) {
        items[counter] = item;
        counter++;
    }

    // initialize permutation generator
    PermutationGenerator pg(indexes, numberOfItems);

    // get number of permutations
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numberOfItems);

    // iterate through all possible permutations
    for(int permutationCount = 0; permutationCount < numOfPermutations - 1; permutationCount++) {
        int numberOfBins = 0;
        for(int itemIndex = 0; itemIndex < numberOfItems; itemIndex++) {
            if(binTotal >= 1) {
                numberOfBins++;
                binTotal = 0;
            }
            binTotal += items[indexes[itemIndex]];
            bin[itemIndex] = items[indexes[itemIndex]];
            indexes = pg.getNextPermutation();
        }
        if(numberOfBins <= lowestNumberOfBins) { //TODO: this is never true?
            std::cout << "optimal" << std::endl;
            optimalBin = bin;
        }
    }

    //delete[] indexes;
    delete[] items;
    delete[] bin;

    return optimalBin;
    /*// initialize variables
    int numberOfItems = itemsVector.at(0);
    double * items = new double[numberOfItems];
    Bins * bins = new Bins(numberOfItems);
    int smallestNumberOfBins;
    int * indexOrder = new int[numberOfItems];

    // removing the number of items in the first index of vector
    itemsVector.erase(itemsVector.begin());
    itemsVector.resize(numberOfItems);

    // copy vector to array for faster accessing
    int counter = 0;
    for(double item: itemsVector) {
        items[counter] = item;
        counter++;
    }

    // initialize the index of items to add to stack of bins
    for(int i = 1; i <= numberOfItems; i++) {
        indexOrder[i - 1] = i;
    }

    // get the first stack of bins
    for(int i = 0; i < numberOfItems; i++) {
        bins->addItemBestFit(items[indexOrder[i] - 1]);
    }

    // smallest number of bins is first iteration results
    smallestNumberOfBins = bins->getNumberOfBins();

    // initialize permutation generator
    PermutationGenerator pg(indexOrder, numberOfItems);

    // get number of permutations
    int numOfPermutations = PermutationGenerator::getNumOfPermutations(numberOfItems);

    // holds the optimal bin stack
    Bins* optimalBinStack = nullptr;

    bool optimalBin = false;

    // iterate through all possible permutations
    for(int permutationCount = 0; permutationCount < numOfPermutations - 1; permutationCount++) {
        indexOrder = pg.getNextPermutation();
        if(!optimalBin) {
            delete bins;
        }
        bins = new Bins(numberOfItems);
        optimalBin = false;
        // add items into bins
        for(int i = 0; i < numberOfItems; i++) {
            bins->addItemNextFit(items[indexOrder[i] - 1]);
        }
        // if number of bins is smaller, than save it.
        if(bins->getCurrentBinIndex() < smallestNumberOfBins) {
            smallestNumberOfBins = bins->getCurrentBinIndex();
            delete optimalBinStack;
            optimalBinStack = bins;
            optimalBin = true;
            optimalBinStack->print();
        }
    }

    // cleanup heap
    delete [] indexOrder;
    delete [] items;
    if(bins != optimalBinStack) {
        delete bins;
    }

    return optimalBinStack;*/
}

int OptimalPacker::getLowestNumberOfBins() {
    return lowestNumberOfBins + 1;
}

void OptimalPacker::print() {
    double binTotal = 0;
    double previousItem = 0;
    int binCount = 0;
    for(int i = 0; i < numberOfItems; i++) {
        if(binTotal <= 0) {
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

        previousItem = optimalBin[i];
    }
}
