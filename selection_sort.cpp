#include <cassert>
#include <iostream>

void selection_sort(int* values, int values_len) {
    for (int i = 0; i < values_len; ++i) {
        int smallest_index = i;
        
        for (int j = i + 1; j < values_len; ++j) {
            if (values[j] < values[smallest_index]) {
                smallest_index = j;
            }
        }

        int auxiliary = values[i];
        values[i] = values[smallest_index];
        values[smallest_index] = auxiliary;
    }
}

int main() {
    int values[] = { 0, 1, 3, 2, 7, 9, 8, 5, 6, 4 };
    int values_len = sizeof(values) / sizeof(int);

    selection_sort(values, values_len);

    for (int i = 0; i < values_len; ++i) {
        assert(values[i] == i);
    }

    std::cout << "Success!\n";
    return 0;
}
