//
// Created by cel on 11/1/22.
//

#include <algorithm>
#include "OfflinePacker.hpp"

Bins * OfflinePacker::packItemsFirstFit(std::string fileName) {
    std::vector<double> items = FileParser::getItemsFromFile(fileName);

    int numberOfBins = items.at(0);
    Bins * bins = new Bins(numberOfBins);

    items.erase(items.begin());
    items.resize(numberOfBins);
    std::sort(items.begin(),items.end());

    for(int i = 0; i < numberOfBins; i++) {
        bins->addItemFirstFit(items.at(i));
    }

    return bins;
}

Bins *OfflinePacker::packItemsBestFit(std::string fileName) {
    std::vector<double> items = FileParser::getItemsFromFile(fileName);

    int numberOfBins = items.at(0);
    Bins * bins = new Bins(numberOfBins);

    items.erase(items.begin());
    items.resize(numberOfBins);
    std::sort(items.begin(),items.end());

    /*for(int i = 0; i < numberOfBins; i++) {
        std::cout << items[i] << std::endl;
    }*/

    for(int i = 0; i < numberOfBins; i++) {
        bins->addItemBestFit(items.at(i));
    }

    return bins;
}

