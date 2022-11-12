/***************************************************************
  Student Name: Collin Lowing
  File Name: Item.cpp
  Project 4

  Stores values for each item and holds the next pointer for a linked list
***************************************************************/

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

Item::~Item() {
    delete next;
}