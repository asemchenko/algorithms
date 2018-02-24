//
// Created by asem on 23.02.18.
//
#include "bubbleSort.h"

void bubbleSort(ElementType elements[], size_t length) {
    for (size_t i = length; i > 1; --i) {
        for (size_t j = 1; j < i; ++j) {
            if (elements[j - 1] > elements[j]) {
                ElementType tmp = elements[j - 1];
                elements[j - 1] = elements[j];
                elements[j] = tmp;
            }
        }
    }
}