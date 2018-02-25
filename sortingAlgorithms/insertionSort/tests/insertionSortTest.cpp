//
// Created by asem on 25.02.18.
//
#include <gtest/gtest.h>
#include <cstdlib>
#include "../insertionSort.h"
#include "../../testingUtilities.h"

TEST(InsertionSortTest, OrderTest) {
    for (int i = 0; i < 100; ++i) {
        ASSERT_TRUE(checkOrder(insertionSort, rand()%1000 /* <-- array size*/ ));
    }
}