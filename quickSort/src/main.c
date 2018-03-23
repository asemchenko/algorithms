#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"

extern unsigned long long comparisonsCount;
extern unsigned long long swapsCount;

ll *createRandArray(ll size) {
    ll *array = malloc(sizeof(ll)*size);
    if(!array) return NULL;
    for (ll i = 0; i < size; ++i) {
        array[i] = (ll)rand()%50;
    }
    return array;
}
void printArray(const char* msg, const ll *array, ll size) {
    printf("%s", msg);
    if (size) {
        printf("%llu", array[0]);
        for (ll i = 1; i < size; ++i) {
            printf(", %llu", array[i]);
        }
        printf("\n");
    }
}
ll *createReverseSortedArray(ll size) {
    ll *array = malloc(sizeof(ll)*size);
    if(!array) return NULL;
    for (ll i = size; i > 0; --i) {
        array[i] = i;
    }
    return array;
}
ll *createSortedArray(ll size) {
    ll *array = malloc(sizeof(ll)*size);
    if(!array) return NULL;
    for (ll i = 0; i < size; ++i) {
        array[i] = i;
    }
    return array;
}
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: <arraySize>\n");
        return 1;
    }
    srand((unsigned int)time(0));
    ll size = strtoll(argv[1], NULL, 10);
    ll *array = createSortedArray(size); 
    if(!array) {
        fprintf(stderr, "Can not allocate memory. Terminating...\n");
        return 1;
    }
    printArray("Unsorted array: ", array, size);
    quickSort(array, 0, size-1);
    printArray("Sorted array: ", array, size);
    printf("%lld\t\t%llu\t\t%llu\n", size, comparisonsCount, swapsCount);
    free(array);
    return 0;
}
