//
// Created by asem on 22.03.18.
//
#include "quickSort.h"
unsigned long long comparisonsCount = 0;
unsigned long long swapsCount = 0;
static void swap(ll *a, ll *b) {
    //++swapsCount;
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}

static ll partition(ll *array, ll firstIndex, ll lastIndex) {
    // Lomuto partition schema
    ll pivot = array[lastIndex];
    ll i = firstIndex;
    for (ll j = firstIndex; j < lastIndex; ++j) {
        //++comparisonsCount;
        if (array[j] < pivot) {
            swap(array + i, array + j);
            ++i;
        }
    }
    swap(array + i, array + lastIndex);
    return i;
}

void quickSort(ll *array, ll firstIndex, ll lastIndex) {
    //++comparisonsCount;
    if (firstIndex < lastIndex) {
        ll border = partition(array, firstIndex, lastIndex);
        quickSort(array, firstIndex, border - 1);
        quickSort(array, border + 1, lastIndex);
    }
}
