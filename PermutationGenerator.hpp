/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.hpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#ifndef COP4534_P3_PERMUTATIONGENERATOR_HPP
#define COP4534_P3_PERMUTATIONGENERATOR_HPP

#include "string"
#include <iostream>
#include <vector>

class PermutationGenerator {
private:
    int numOfItems;
    int *perm;
public:
    PermutationGenerator(int *perm, int numOfItems);

    void printPermutation(int *permutation, int size);

    int *getNextPermutation();

    void swap(int a, int b);

    static int getNumOfPermutations(int numOfItems);


};


#endif //COP4534_P3_PERMUTATIONGENERATOR_HPP
