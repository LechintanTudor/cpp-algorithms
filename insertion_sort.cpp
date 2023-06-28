#include <cassert>
#include <iostream>

void insertion_sort(int* values, int values_len) {
    for (int i = 1; i < values_len; ++i) {
        int key = values[i];
        int j = i - 1;
        
        while (j >= 0 && key < values[j]) {
            values[j + 1] = values[j];
            j = j - 1;
        }

        values[j + 1] = key;
    }
}

int main() {
    int values[] = { 0, 1, 3, 2, 7, 9, 8, 5, 6, 4 };
    int values_len = sizeof(values) / sizeof(int);

    insertion_sort(values, values_len);

    for (int i = 0; i < values_len; ++i) {
        assert(values[i] == i);        
    }

    std::cout << "Success!\n";
    return 0;
}
