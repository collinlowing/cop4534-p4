/***************************************************************
  Student Name: Collin Lowing
  File Name: main.cpp
  Project 4

  Runs all packing algorithms and prints results
***************************************************************/

#include "OnlinePacker.hpp"
#include "OfflinePacker.hpp"
#include "OptimalPacker.hpp"

int main() {
    // initialize variables
    std::string itemsFileName = "items.txt";

    int optimalSolutionNumberOfBins;

    int onlineFirstFitNumberOfBins;
    int onlineNextFitNumberOfBins;
    int onlineBestFitNumberOfBins;

    int offlineFirstFitNumberOfBins;
    int offlineBestFitNumberOfBins;

    // Online Algorithm
    Bins *onlineFirstFit = OnlinePacker::packItemsFirstFit(itemsFileName);
    onlineFirstFitNumberOfBins = onlineFirstFit->getNumberOfBins();

    Bins *onlineNextFit = OnlinePacker::packItemsNextFit(itemsFileName);
    onlineNextFitNumberOfBins = onlineNextFit->getNumberOfBins();

    Bins *onlineBestFit = OnlinePacker::packItemsBestFit(itemsFileName);
    onlineBestFitNumberOfBins = onlineBestFit->getNumberOfBins();

    // Offline Algorithm
    Bins *offlineFirstFit = OfflinePacker::packItemsFirstFit(itemsFileName);
    offlineFirstFitNumberOfBins = offlineFirstFit->getNumberOfBins();

    Bins *offlineBestFit = OfflinePacker::packItemsBestFit(itemsFileName);
    offlineBestFitNumberOfBins = offlineBestFit->getNumberOfBins();

    std::cout << "Generating the optimal solution... This may take about 1 minute" << std::endl;
    OptimalPacker op;
    op.getOptimalBinStack(itemsFileName);
    optimalSolutionNumberOfBins = op.getLowestNumberOfBins();

    // Print number of bins from results in a table
    printf("Policy\t\t\t\tTotal Bins Used\n");
    printf("Optimal Solution\t\t\t\t%d\n", optimalSolutionNumberOfBins);
    printf("Online Algorithm\n");
    printf("First Fit\t\t\t\t%d\n", onlineFirstFitNumberOfBins);
    printf("Next Fit\t\t\t\t%d\n", onlineNextFitNumberOfBins);
    printf("Best Fit\t\t\t\t%d\n", onlineBestFitNumberOfBins);
    printf("Offline Algorithm\n");
    printf("First Fit\t\t\t\t%d\n", offlineFirstFitNumberOfBins);
    printf("Best Fit\t\t\t\t%d\n\n", offlineBestFitNumberOfBins);

    // Print Optimal bins
    std::cout << "Optimal Solution:" << std::endl;
    op.print();

    // Print Online bins
    std::cout << "Online First Fit:" << std::endl;
    onlineFirstFit->print();

    std::cout << "Online Next Fit:" << std::endl;
    onlineNextFit->print();

    std::cout << "Online Best Fit:" << std::endl;
    onlineBestFit->print();

    // Print Offline bins
    std::cout << "Offline First Fit:" << std::endl;
    offlineFirstFit->print();

    std::cout << "Offline Best Fit:" << std::endl;
    offlineBestFit->print();

    // cleanup heap
    delete onlineFirstFit;
    delete onlineNextFit;
    delete onlineBestFit;
    delete offlineFirstFit;
    delete offlineBestFit;

    return 0;
}
