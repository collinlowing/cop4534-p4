//
// Created by cel on 11/1/22.
//

#ifndef COP4534_P4_BINS_HPP
#define COP4534_P4_BINS_HPP

#include "Item.hpp"
#include <vector>
#include <iostream>

class Bins {
private:
    Item** bins;
    int size;
    int currentBinIndex;
    double MAX_BIN_OCCUPANCY = 1.0;
public:
    Bins(int size);
    void addItemFirstFit(double itemSize);
    void addItemNextFit(double itemSize);
    void addItemBestFit(double itemSize);
    void print();

    double getBinOccupancy(int index);
    bool canBinFitItem(int index, double itemSize);
};


#endif //COP4534_P4_BINS_HPP
