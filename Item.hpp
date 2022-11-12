/***************************************************************
  Student Name: Collin Lowing
  File Name: Item.hpp
  Project 4

  Stores values for each item and holds the next pointer for a linked list
***************************************************************/

#ifndef COP4534_P4_ITEM_HPP
#define COP4534_P4_ITEM_HPP


class Item {
private:
    double itemSize;
    Item *next;
public:
    Item(double itemSize);

    double getItemSize();

    Item *getNext();

    void setNext(Item *item);

    ~Item();
};


#endif //COP4534_P4_ITEM_HPP
