//
// Created by asem on 24.02.18.
//
#include <gtest/gtest.h>
#include <cstdlib>
#include "../bubbleSort.h"
#include "../../testingUtilities.h"

TEST(BubbleSortTest, OrderTest) {
    for (int i = 0; i < 100; ++i) {
        ASSERT_TRUE(checkOrder(bubbleSort, rand()%1000 /* <-- array size*/ ));
    }
}