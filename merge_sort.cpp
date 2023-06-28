#include <cassert>
#include <iostream>
#include <vector>

void merge_sort(int* values, int values_len);
void split_merge(int* src, int* dst, int left, int right);
void merge(const int* src, int* dst, int left, int middle, int right);

void merge_sort(int* values, int values_len) {
    std::vector<int> values_copy(values, values + values_len);
    split_merge(values_copy.data(), values, 0, values_len);
}

void split_merge(int* src, int* dst, int left, int right) {
    if (right - left <= 1) {
        return;
    }

    int middle = left + (right - left) / 2;
    split_merge(dst, src, left, middle);
    split_merge(dst, src, middle, right);
    merge(src, dst, left, middle, right);
}

void merge(const int* src, int* dst, int left, int middle, int right) {
    int i = left;
    int j = middle;

    for (int k = left; k < right; ++k) {
        if (i < middle && (j >= right || !(src[j] < src[i]))) {
            dst[k] = src[i];
            i += 1;
        } else {
            dst[k] = src[j];
            j += 1;
        }
    }
}

int main() {
    int values[] = { 0, 1, 3, 2, 7, 9, 8, 5, 6, 4 };
    int values_len = sizeof(values) / sizeof(int);

    merge_sort(values, values_len);

    for (int i = 0; i < values_len; ++i) {
        assert(values[i] == i);        
    }

    std::cout << "Success!\n";
    return 0;
}
