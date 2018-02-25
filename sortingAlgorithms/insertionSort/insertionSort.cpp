//
// Created by asem on 25.02.18.
//

void insertionSort(long long elements[], int length) {
    for (int i = 1; i < length; ++i) {
        long long cur = elements[i];
        for (int j = i; j >= 0; --j) {
            if(elements[j-1] > cur) {
                elements[j] = elements[j-1];
            } else {
                elements[j] = cur;
                break;
            }
        }
    }
}
