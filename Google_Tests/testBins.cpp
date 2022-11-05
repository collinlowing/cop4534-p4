//
// Created by cel on 11/5/22.
//

#include "gtest/gtest.h"
#include "../Bins.hpp"
#include <vector>

TEST(BinsTest, FirstFit) {
    int numberOfBins = 12;
    Bins * bins = new Bins(numberOfBins);

    std::vector<double> items = {
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

    for(double item: items) {
        bins->addItemFirstFit(item);
    }

    Item * it = bins->getItems(0);

    ASSERT_TRUE(it != nullptr);

    double firstItem = it->getItemSize();

    it = it->getNext();
    double secondItem = it->getItemSize();

    it = it->getNext();
    double thirdItem = it->getItemSize();

    EXPECT_EQ(firstItem, items.at(0));
    EXPECT_EQ(secondItem, items.at(1));
    EXPECT_EQ(thirdItem, items.at(2));

    it = it->getNext();
    ASSERT_TRUE(it == nullptr);

    it = bins->getItems(1);
    ASSERT_TRUE(it != nullptr);
    EXPECT_EQ(it->getItemSize(), items.at(3));

    bins->print();
}

TEST(BinsTest, NextFit) {
    int numberOfBins = 12;
    Bins * bins = new Bins(numberOfBins);

    std::vector<double> items = {
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

    for(double item: items) {
        bins->addItemNextFit(item);
    }

    Item * it = bins->getItems(0);

    ASSERT_TRUE(it != nullptr);

    double firstItem = it->getItemSize();

    it = it->getNext();
    double secondItem = it->getItemSize();

    it = it->getNext();
    double thirdItem = it->getItemSize();

    EXPECT_EQ(firstItem, items.at(0));
    EXPECT_EQ(secondItem, items.at(1));
    EXPECT_EQ(thirdItem, items.at(2));

    it = it->getNext();
    ASSERT_TRUE(it == nullptr);

    it = bins->getItems(1);
    ASSERT_TRUE(it != nullptr);
    EXPECT_EQ(it->getItemSize(), items.at(3));

    bins->print();
}

TEST(BinsTest, BestFit) {
    int numberOfBins = 12;
    Bins * bins = new Bins(numberOfBins);

    std::vector<double> items = {
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

    for(double item: items) {
        bins->addItemBestFit(item);
    }

    Item * it = bins->getItems(0);

    ASSERT_TRUE(it != nullptr);

    double firstItem = it->getItemSize();

    it = it->getNext();
    double secondItem = it->getItemSize();

    it = it->getNext();
    double thirdItem = it->getItemSize();

    EXPECT_EQ(firstItem, items.at(0));
    EXPECT_EQ(secondItem, items.at(1));
    EXPECT_EQ(thirdItem, items.at(2));

    it = it->getNext();
    ASSERT_TRUE(it == nullptr);

    it = bins->getItems(1);
    ASSERT_TRUE(it != nullptr);
    EXPECT_EQ(it->getItemSize(), items.at(3));

    bins->print();
}