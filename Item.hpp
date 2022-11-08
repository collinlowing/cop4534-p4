//
// Created by cel on 11/1/22.
//

#ifndef COP4534_P4_ITEM_HPP
#define COP4534_P4_ITEM_HPP


class Item {
private:
    double itemSize;
    Item * next;
public:
    Item(double itemSize);
    double getItemSize();
    Item* getNext();
    void setNext(Item* item);
    ~Item();
};


#endif //COP4534_P4_ITEM_HPP
