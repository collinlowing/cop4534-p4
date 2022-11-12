/***************************************************************
  Student Name: Collin Lowing
  File Name: OfflinePacker.hpp
  Project 4

  Sorts the items and adds them using the different packing algorithms to bins
***************************************************************/

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
