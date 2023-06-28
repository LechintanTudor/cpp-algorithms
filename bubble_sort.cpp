#include <cassert>
#include <iostream>

void bubble_sort(int* values, int values_len) {
    for (int i = 0; i < values_len - 1; ++i) {
        bool swapped = false; 

        for (int j = 0; j < values_len - i - 1; ++j) {
            if (values[j + 1] < values[j]) {
                int auxiliary = values[j];
                values[j] = values[j + 1];
                values[j + 1] = auxiliary;        
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int values[] = { 0, 1, 3, 2, 7, 9, 8, 5, 6, 4 };
    int values_len = sizeof(values) / sizeof(int);

    bubble_sort(values, values_len);

    for (int i = 0; i < values_len; ++i) {
        assert(values[i] == i);        
    }

    std::cout << "Success!\n";
    return 0;
}
