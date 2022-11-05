//
// Created by cel on 11/1/22.
//

#include "Bins.hpp"

Bins::Bins(int size) {
    this->size = size;
    currentBinIndex = 0;

    bins = new Item*[size];
    for(int i = 0; i < size; i++) {
        bins[i] = nullptr;
    }
}

void Bins::addItemFirstFit(double itemSize) {
    Item * newItem = new Item(itemSize);
    bool itemPlaced = false;
    for(int i = 0; i < size; i++) {
        if(canBinFitItem(i, itemSize)) {
            bins[i] = newItem;
            itemPlaced = true;
            break;
        }
    }
    if(!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
    else {
        currentBinIndex++;
    }
}

void Bins::addItemNextFit(double itemSize) {
    Item * newItem = new Item(itemSize);
    bool itemPlaced = false;

    if(canBinFitItem(currentBinIndex, itemSize)) {
        bins[currentBinIndex] = newItem;
        itemPlaced = true;
    }

    if(!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
    else {
        currentBinIndex++;
    }
}

void Bins::addItemBestFit(double itemSize) {
    Item * newItem = new Item(itemSize);
    bool itemPlaced = false;
    double occupancy = 0;

    for(int i = 0; i < size; i++) {
        if(canBinFitItem(i, itemSize) && occupancy <= getBinOccupancy(i)) {
            bins[i] = newItem;
            occupancy = getBinOccupancy(i);
            itemPlaced = true;
        }
    }
    if(!itemPlaced) {
        std::cout << "Item of size " << itemSize << " cannot fit in allocated bins. Discarded" << std::endl;
    }
}



void Bins::print() {
    for(int i = 0; i < size; i++) {
        std::cout << "b" << i << ": ";
        Item* head = bins[i];
        while(head != nullptr) {
            if(head->getNext() == nullptr) {
                std::cout << head->getItemSize();
            }
            else {
                std::cout << head->getItemSize() << ", ";
            }
            head = head->getNext();
        }
        std::cout << std::endl;
    }
}

double Bins::getBinOccupancy(int index) {
    Item * head = bins[index];
    double totalOccupancy = 0.0;

    if(head == nullptr) {
        return 0.0;
    }

    while(head != nullptr) {
        totalOccupancy += head->getItemSize();
        head = head->getNext();
    }

    return totalOccupancy;
}

bool Bins::canBinFitItem(int index, double itemSize) {
    if(bins[index] == nullptr && itemSize <= MAX_BIN_OCCUPANCY) {
        return true;
    }
    else {
        double binOccupancy = getBinOccupancy(index);

        if((binOccupancy + itemSize) <= MAX_BIN_OCCUPANCY) {
            return true;
        }
    }
    return false;
}
