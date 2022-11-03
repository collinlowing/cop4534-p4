//
// Created by cel on 11/1/22.
//

#ifndef COP4534_P4_BIN_HPP
#define COP4534_P4_BIN_HPP

#include "Item.hpp"

class Bin {
private:
    Item* head;
    Item* tail;
    int size;
public:
    Bin(int size);
    void addItem(double itemSize);
    void print();
};


#endif //COP4534_P4_BIN_HPP
