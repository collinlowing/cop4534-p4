//
// Created by cel on 11/1/22.
//

#ifndef COP4534_P4_ONLINEPACKER_HPP
#define COP4534_P4_ONLINEPACKER_HPP

#include "Bins.hpp"
#include "FileParser.hpp"

class OnlinePacker {
public:
    static Bins* packItemsFirstFit(std::string fileName);
    static Bins* packItemsNextFit(std::string fileName);
    static Bins* packItemsBestFit(std::string fileName);
};


#endif //COP4534_P4_ONLINEPACKER_HPP
