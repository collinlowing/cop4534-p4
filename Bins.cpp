//
// Created by cel on 11/1/22.
//

#include "Bins.hpp"

Bins::Bins(int size) {
    this->size = size;

    bins = new Item*[size];
    for(int i = 0; i < size; i++) {
        bins[i] = nullptr;
    }
}

void Bins::addItem(double itemSize) {
    Item * newItem = new Item(itemSize);
    bool itemPlaced = false;
    for(int i = 0; i < size; i++) {
        if(canBinFitItem(i, 0)) {
            bins[i] = newItem;
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
