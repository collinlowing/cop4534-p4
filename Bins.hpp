/***************************************************************
  Student Name: Collin Lowing
  File Name: Bins.hpp
  Project 4

  Manages Items in bins and different packing algorithms
***************************************************************/

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

    Item *getItems(int index);
    void insert(int index, double itemSize);
    int getNumberOfBins();
    int getCurrentBinIndex();
    ~Bins();
};


#endif //COP4534_P4_BINS_HPP
