#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <memory>
#include "bubbleSort/bubbleSort.h"
#include "selectionSort/selectionSort.h"

template<typename Function, typename ... Arguments>
int measureExecutionTime(Function function, Arguments ... arguments) {
    using namespace std::chrono;
    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    function(arguments ...);
    high_resolution_clock::time_point finishTime = high_resolution_clock::now();
    return duration_cast<microseconds>(finishTime - startTime).count();
}

std::shared_ptr<ElementType> getRandomArray(long long length) {
    auto ptr = std::shared_ptr<ElementType>(new ElementType[length], [](ElementType *p) { delete[] p;});
    for (int i = 0; i < length; ++i) {
        ptr.get()[i] = rand();
    }
    return ptr;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: sortingAlgorithms <arraySize>\n");
        exit(1);
    }
    long long arraySize = atoll(argv[1]);
    printf("Array size: %lld\n==================================\n", arraySize);
    auto array = getRandomArray(arraySize);
    printf("Bubble sorting: %d microseconds\n", measureExecutionTime(bubbleSort, array.get(), arraySize));
    printf("Selection sorting: %d microseconds\n", measureExecutionTime(selectionSort, array.get(), arraySize));
}