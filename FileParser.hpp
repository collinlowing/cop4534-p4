/***************************************************************
  Student Name: Collin Lowing
  File Name: FileParser.hpp
  Project 4

  Gets all the data from the file for use elsewhere
***************************************************************/

#ifndef COP4534_P3_FILEPARSER_HPP
#define COP4534_P3_FILEPARSER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class FileParser {
public:
    static std::vector<double> getItemsFromFile(std::string fileName);

    static double stringToDouble(std::string str);
};


#endif //COP4534_P3_FILEPARSER_HPP
