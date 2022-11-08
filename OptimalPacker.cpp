//
// Created by cel on 11/7/22.
//

#include "OptimalPacker.hpp"
#include "FileParser.hpp"
#include "PermutationGenerator.hpp"

Bins *OptimalPacker::getOptimalBinStack(std::string fileName) {
    // get items from file
    std::vector<double> itemsVector = FileParser::getItemsFromFile(fileName);
    // initialize variables
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
        if(bins->getNumberOfBins() < smallestNumberOfBins) {
            smallestNumberOfBins = bins->getNumberOfBins();
            delete optimalBinStack;
            optimalBinStack = bins;
            optimalBin = true;
        }
    }

    // cleanup
    delete [] indexOrder;
    delete [] items;
    delete bins;

    return optimalBinStack;
}
