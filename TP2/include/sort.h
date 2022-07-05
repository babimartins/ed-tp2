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

    int partition(Vector<T> vector, int start, int end, int median) {
        T pivot = vector.get(start);

        if (median > 1) {
            Vector<T> medianVector;
            for (int i = start; i < start + median; ++i) {
                medianVector.push(vector[i], i - start);
            }
            insertion(&medianVector, 0, medianVector.length() - 1);
            pivot = medianVector[median / 2];
        }

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

    void quicksort(Vector<T> vector, int start, int end, int median, int s) {
        if (start >= end)
            return;

        int partitionSize = end - start + 1;
        if ((partitionSize <= s) || (s < partitionSize && partitionSize < median)) {
            insertion(&vector, start, end);
        } else {
            int p = partition(vector, start, end, median);
            quicksort(vector, start, p - 1, median, s);
            quicksort(vector, p + 1, end, median, s);
        }
    }
};

#endif //SORT_H
