//
// Created by cel on 11/1/22.
//

#include "Bin.hpp"

Bin::Bin(int size) {
    this->size = size;
    head = nullptr;
    tail = nullptr;
}

void Bin::addItem(double itemSize) {
    Item * newItem = new Item(itemSize);
    if(head == nullptr) {
        head = newItem;
        tail = head;
    }
    else {
        tail->setNext(newItem);
        tail = tail->getNext();
    }
}

void Bin::print() {

}
