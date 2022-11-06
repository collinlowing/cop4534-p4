//
// Created by cel on 11/1/22.
//

#include "OnlinePacker.hpp"

Bins * OnlinePacker::packItemsFirstFit(std::string fileName) {
    std::vector<double> items = FileParser::getItemsFromFile(fileName);

    int numberOfBins = items.at(0);
    Bins * bins = new Bins(numberOfBins);

    for(int i = 1; i < numberOfBins + 1; i++) {
        bins->addItemFirstFit(items.at(i));
    }

    return bins;
}

Bins *OnlinePacker::packItemsNextFit(std::string fileName) {
    std::vector<double> items = FileParser::getItemsFromFile(fileName);

    int numberOfBins = items.at(0);
    Bins * bins = new Bins(numberOfBins);

    for(int i = 1; i < numberOfBins + 1; i++) {
        bins->addItemNextFit(items.at(i));
    }

    return bins;
}

Bins *OnlinePacker::packItemsBestFit(std::string fileName) {
    std::vector<double> items = FileParser::getItemsFromFile(fileName);

    int numberOfBins = items.at(0);
    Bins * bins = new Bins(numberOfBins);

    for(int i = 1; i < numberOfBins + 1; i++) {
        bins->addItemBestFit(items.at(i));
    }

    return bins;
}
