//
// Created by asem on 24.02.18.
//
#include <gtest/gtest.h>
#include "../bubbleSort.h"
#include <cstdlib>

TEST(BubbleSortTest, OrderTest) {
    // testing does algorithm really sort elements
    // implementation below - bullshit
    srand(time(0));
    int length = rand() % 100;
    ElementType *elements = new ElementType[length];
    for (int i = 0; i < 5000; ++i) {
        for (int i = 0; i < length; ++i) {
            elements[i] = rand();
        }
        bubbleSort(elements, length);
        bool r = true;
        for (int j = 1; j < length; ++j) {
            if (elements[j - 1] > elements[j]) r = false;
        }
        ASSERT_TRUE(r);
    }
    delete[] elements;
}