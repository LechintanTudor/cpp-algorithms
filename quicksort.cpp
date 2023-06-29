#include <cassert>
#include <iostream>

void quicksort(int* values, int values_len);
void quicksort_inner(int* values, int left, int right);
int partition(int* values, int left, int right);

void quicksort(int* values, int values_len) {
    quicksort_inner(values, 0, values_len - 1);
}

void quicksort_inner(int* values, int left, int right) {
    if (left >= right || left < 0) {
        return;
    }

    int pivot_index = partition(values, left, right);
    quicksort_inner(values, left, pivot_index - 1);
    quicksort_inner(values, pivot_index + 1, right);    
}

int partition(int* values, int left, int right) {
    int pivot = values[right];
    int i = left;

    for (int j = left; j < right; ++j) {
        if (values[j] <= pivot) {
            int auxiliary = values[i];
            values[i] = values[j];
            values[j] = auxiliary;
            i += 1;
        }
    }

    int auxiliary = values[i];
    values[i] = values[right];
    values[right] = auxiliary;

    return i;
}

int main() {
    int values[] = { 0, 1, 3, 2, 7, 9, 8, 5, 6, 4 };
    int values_len = sizeof(values) / sizeof(int);

    quicksort(values, values_len);

    for (int i = 0; i < values_len; ++i) {
        assert(values[i] == i);        
    }

    std::cout << "Success!\n";
    return 0;
}
