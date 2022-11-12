/***************************************************************
  Student Name: Collin Lowing
  File Name: Bins.cpp
  Project 4

  Manages Items in bins and different packing algorithms
***************************************************************/

#include "Bins.hpp"

Bins::Bins(int size) {
    this->size = size;
    currentBinIndex = 0;

    bins = new Item *[size];
    for (int i = 0; i < size; i++) {
        bins[i] = nullptr;
    }
}

void Bins::addItemFirstFit(double itemSize) {
    bool itemPlaced = false;
    for (int i = 0; i < size; i++) {
        if (canBinFitItem(i, itemSize)) {
            insert(i, itemSize);
            itemPlaced = true;
            break;
        }
    }
    if (!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
}

void Bins::addItemNextFit(double itemSize) {
    bool itemPlaced = false;

    if (canBinFitItem(currentBinIndex, itemSize)) {
        insert(currentBinIndex, itemSize);
        itemPlaced = true;
    } else if (currentBinIndex < size) {
        currentBinIndex++;
        insert(currentBinIndex, itemSize);
        itemPlaced = true;
    }

    if (!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
}

void Bins::addItemBestFit(double itemSize) {
    bool itemPlaced = false;
    double biggestOccupancy = 0;
    int bestIndex = 0;
    double currentOccupancy;

    for (int i = 0; i < size; i++) {
        currentOccupancy = getBinOccupancy(i) + itemSize;
        if (currentOccupancy > biggestOccupancy && currentOccupancy <= 1) {
            bestIndex = i;
            biggestOccupancy = currentOccupancy;
        }
    }
    if (canBinFitItem(bestIndex, itemSize)) {
        insert(bestIndex, itemSize);
        itemPlaced = true;
    }

    if (!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
}

void Bins::print() {
    for (int i = 0; i < getNumberOfBins(); i++) {
        std::cout << "b" << i << ": ";
        Item *head = bins[i];
        while (head != nullptr) {
            if (head->getNext() == nullptr) {
                std::cout << head->getItemSize();
            } else {
                std::cout << head->getItemSize() << ", ";
            }
            head = head->getNext();
        }
        std::cout << std::endl;
    }
}

double Bins::getBinOccupancy(int index) {
    Item *head = bins[index];
    double totalOccupancy = 0.0;

    if (head == nullptr) {
        return 0.0;
    }

    while (head != nullptr) {
        totalOccupancy += head->getItemSize();
        head = head->getNext();
    }

    return totalOccupancy;
}

bool Bins::canBinFitItem(int index, double itemSize) {
    if (bins[index] == nullptr && itemSize <= MAX_BIN_OCCUPANCY) {
        return true;
    } else {
        double binOccupancy = getBinOccupancy(index);

        if ((binOccupancy + itemSize) <= MAX_BIN_OCCUPANCY) {
            return true;
        }
    }
    return false;
}

Item *Bins::getItems(int index) {
    return bins[index];
}

void Bins::insert(int index, double itemSize) {
    Item *newItem = new Item(itemSize);

    Item *head = bins[index];

    if (head == nullptr) {
        bins[index] = newItem;
    } else {
        while (head->getNext() != nullptr) {
            head = head->getNext();
        }
        head->setNext(newItem);
    }
}

Bins::~Bins() {
    for (int i = 0; i < size; i++) {
        delete bins[i];
    }

    delete[] bins;
}

int Bins::getNumberOfBins() {
    int counter = 0;
    do {
        if (bins[counter] == nullptr) {
            break;
        }
        counter++;
    } while (true);

    return counter;
}

int Bins::getCurrentBinIndex() {
    return currentBinIndex;
}
