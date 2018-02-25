//
// Created by asem on 25.02.18.
//

/*
 *  function implemented below used
 *  in unit testing of sorting
 *  algorithms
 */
#ifndef SORTING_ALGORITHMS_TESTING_UTILITIES_H
#define SORTING_ALGORITHMS_TESTING_UTILITIES_H

#include <cstdlib>
#include <memory>
/*
 *  this function checks sorting function
 *  directly on elements order
 *  without stability, e.g.
 */
template <typename ReturnType, typename ElementType, typename LengthType, typename ... OtherArgs>
bool checkOrder(ReturnType (&sortingFunction)(ElementType[], LengthType, OtherArgs ... ),
                int arraySize, OtherArgs ... args) {
    // preparing array
    auto elements = std::unique_ptr<ElementType[]>(new ElementType[arraySize]);
    for (int i = 0; i < arraySize; ++i) {
        elements[i] = rand();
    }
    // calling testing function
    sortingFunction(elements.get(), static_cast<LengthType>(arraySize), args ...);
    // checking does array sorted
    for (int i = 1; i < arraySize; ++i) {
        if (elements[i-1] > elements[i]) return false;
    }
    return true;
}

#endif //SORTING_ALGORITHMS_TESTING_UTILITIES_H
