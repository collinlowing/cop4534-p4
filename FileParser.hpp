//
// Created by cel on 10/11/22.
//

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
