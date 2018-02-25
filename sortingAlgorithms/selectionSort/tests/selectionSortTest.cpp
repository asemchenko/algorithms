//
// Created by asem on 25.02.18.
//
#include <gtest/gtest.h>
#include <cstdlib>
#include "../selectionSort.h"
#include "../../testingUtilities.h"

TEST(SelectionSortTest, OrderTest) {
    for (int i = 0; i < 100; ++i) {
        ASSERT_TRUE(checkOrder(selectionSort, rand()%1000 /* <-- array size*/ ));
    }
}