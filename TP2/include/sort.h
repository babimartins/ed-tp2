#ifndef SORT_H
#define SORT_H

#include <iostream>
#include "vector.h"

template <typename T> class Sort {
public:
    Sort() = default;

    void insertion(Vector<T>* vector, int start, int end) {
        for (int i = start; i <= end; i++) {
            T el = (*vector)[i];
            int j = i - 1;
            while (j >= 0 && el < (*vector)[j]) {
                (*vector)[j + 1] = (*vector)[j];
                --j;
            }
            (*vector)[j + 1] = el;
        }
    }

    int partition(Vector<T> vector, int start, int end) {
        T pivot = vector.get(start);

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (vector[i] <= pivot)
                count++;
        }

        int pivotIndex = start + count;
        vector.swap(pivotIndex, start);

        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (vector[i] <= pivot) {
                i++;
            }

            while (vector.get(j) > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                vector.swap(i++, j--);
            }
        }

        return pivotIndex;
    }

    void quickSort(Vector<T> vector, int start, int end) {
        if (start >= end)
            return;

        int p = partition(vector, start, end);

        quickSort(vector, start, p - 1);

        quickSort(vector, p + 1, end);
    }
};

#endif //SORT_H
