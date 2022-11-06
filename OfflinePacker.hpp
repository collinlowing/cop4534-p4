//
// Created by cel on 11/1/22.
//

#ifndef COP4534_P4_OFFLINEPACKER_HPP
#define COP4534_P4_OFFLINEPACKER_HPP

#include "Bins.hpp"
#include "FileParser.hpp"

class OfflinePacker {
public:
    static Bins* packItemsFirstFit(std::string fileName);
    static Bins* packItemsBestFit(std::string fileName);
};


#endif //COP4534_P4_OFFLINEPACKER_HPP
