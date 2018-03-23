#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "bubbleSort/bubbleSort.h"
#include "selectionSort/selectionSort.h"
#include "insertionSort/insertionSort.h"

template<typename Function, typename ... Arguments>
int measureExecutionTime(Function function, Arguments ... arguments) {
    using namespace std::chrono;
    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    function(arguments ...);
    high_resolution_clock::time_point finishTime = high_resolution_clock::now();
    return duration_cast<microseconds>(finishTime - startTime).count();
}

std::unique_ptr<ElementType[]> getRandomArray(long long length) {
    auto ptr = std::unique_ptr<ElementType[]>(new ElementType[length]);
    for (int i = 0; i < length; ++i) {
        ptr[i] = rand();
    }
    return ptr;
}
std::unique_ptr<ElementType[]> randomShuffleArray(std::unique_ptr<ElementType[]> &array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = rand();
    }
    return std::move(array);
}
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: sortingAlgorithms <arraySize>\n");
        exit(1);
    }
    long long arraySize = atoll(argv[1]);
    printf("Array size: %lld\n==================================\n", arraySize);
    auto array = getRandomArray(arraySize);
    printf("   Bubble sorting: %9d microseconds\n", measureExecutionTime(bubbleSort, array.get(), arraySize));
    array = randomShuffleArray(array, arraySize);
    printf("Selection sorting: %9d microseconds\n", measureExecutionTime(selectionSort, array.get(), arraySize));
    array = randomShuffleArray(array, arraySize);
    printf("Insertion sorting: %9d microseconds\n", measureExecutionTime(insertionSort, array.get(), arraySize));
}
