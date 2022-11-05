//
// Created by cel on 11/5/22.
//

#include "gtest/gtest.h"
#include "../FileParser.hpp"
#include <vector>

TEST(ParserTest, GetItems) {
    std::vector<double> fileItems = FileParser::getItemsFromFile("items.txt");

    std::vector<double> items = {
            12,
            0.41,
            0.33,
            0.245,
            0.19,
            0.5,
            0.755,
            0.33,
            0.22,
            0.5,
            0.33,
            0.81,
            0.37
    };

    for(int i = 0; i < 13; i++) {
        EXPECT_EQ(fileItems[i], items[i]);
    }
}