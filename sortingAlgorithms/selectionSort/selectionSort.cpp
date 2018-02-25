//
// Created by asem on 25.02.18.
//
#include <utility>
#include <algorithm>
void selectionSort(long long elements[], int length) {
    long long minElement, minElementIndex;
    for (int i = 0; i < length - 1; ++i) {
        minElementIndex = i;
        minElement = elements[minElementIndex];
        for (int j = i; j < length; ++j) {
            if (minElement > elements[j]) {
                minElementIndex = j;
                minElement = elements[minElementIndex];
            }
        }
        std::swap(elements[i], elements[minElementIndex]);
    }
}