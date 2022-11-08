/***************************************************************
  Student Name: Collin Lowing
  File Name: PermutationGenerator.cpp
  Project 3

  Generates permutations of traversals
***************************************************************/

#include "PermutationGenerator.hpp"

PermutationGenerator::PermutationGenerator(int *perm, int numOfItems) {
    this->perm = perm;
    this->numOfItems = numOfItems;
}

int *PermutationGenerator::getNextPermutation() {
    int binStackSize = numOfItems - 1;

    int m, k, p, q;
    m = binStackSize - 2;
    while (perm[m] > perm[m + 1]) {
        m = m - 1;
    }
    k = binStackSize - 1;
    while (perm[m] > perm[k]) {
        k = k - 1;
    }
    swap(m, k);
    p = m + 1;
    q = binStackSize - 1;
    while (p < q) {
        swap(p, q);
        p++;
        q--;
    }
    //printPermutation(perm, binStackSize); // used for testing
    return perm;
}

void PermutationGenerator::swap(int a, int b) {
    int temp = perm[a];
    perm[a] = perm[b];
    perm[b] = temp;
}

void PermutationGenerator::printPermutation(int *permutation, int size) {
    std::cout << "route: ";
    for (int i = 0; i < size; i++) {
        std::cout << permutation[i] << " ";
    }
    std::cout << std::endl;
}

int PermutationGenerator::getNumOfPermutations(int numOfItems) {
    int factorial = 1;

    if (numOfItems < 0) {
        std::cout << "the number of cities to permute must be 0 or greater" << std::endl;
        return -1;
    }

    for (int i = 1; i <= numOfItems; i++) {
        factorial *= i;
    }

    return factorial;
}