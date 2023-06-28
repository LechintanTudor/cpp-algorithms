#include <cassert>
#include <iostream>
#include <optional>

std::optional<int> binary_search(const int* values, int values_len, int value) {
    int left = 0;
    int right = values_len - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (values[middle] < value) {
            left = middle + 1;
        } else if (values[middle] == value) {
            return middle;
        } else {
            right = middle - 1;
        }
    }

    return {};
}

int main() {
    int values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int values_len = sizeof(values) / sizeof(int);

    auto result1 = binary_search(values, values_len, 0);
    assert(result1 == std::optional(0));

    auto result2 = binary_search(values, values_len, 5);
    assert(result2 == std::optional(5));

    auto result3 = binary_search(values, values_len, 9);
    assert(result3 == std::optional(9));
    
    auto result4 = binary_search(values, values_len, 15);
    assert(!result4.has_value());

    auto result5 = binary_search(values, values_len, 20);
    assert(!result5.has_value());

    std::cout << "Success!\n";
    return 0;
}
