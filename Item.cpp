//
// Created by cel on 11/1/22.
//

#include "Item.hpp"

Item::Item(double itemSize) {
    this->itemSize = itemSize;
    next = nullptr;
}

double Item::getItemSize() {
    return itemSize;
}

Item *Item::getNext() {
    return next;
}

void Item::setNext(Item* item) {
    next = item;
}
