//
// Created by cel on 10/11/22.
//

#include "FileParser.hpp"

std::vector<double> FileParser::getItemsFromFile(std::string fileName) {
    std::vector<double> values;
    int i = 0;
    std::string line;
    std::ifstream fileInputStream(fileName);

    // if fileInputStream is not opened
    if (!fileInputStream.is_open()) {
        std::cout << "fatal error: " << fileName << " could not be opened." << std::endl;
        return values;
    }

    // read lines from file
    while (std::getline(fileInputStream, line)) {
        // convert string to double value
        values.push_back(stringToDouble(line));
        i++;
    }

    fileInputStream.close();

    return values;
}

double FileParser::stringToDouble(std::string str) {
    double d = 0;
    std::istringstream ss(str);
    ss >> d;
    return d;
}