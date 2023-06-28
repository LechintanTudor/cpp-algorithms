#include <cassert>
#include <iostream>
#include <optional>

std::optional<int> sequential_search(const int* values, int values_len, int value) {
    for (int i = 0; i < values_len; ++i) {
        if (values[i] == value) {
            return std::optional(i);
        }
    }

    return {};
}

int main() {
    int values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int values_len = sizeof(values) / sizeof(int);

    auto result1 = sequential_search(values, values_len, 0);
    assert(result1 == std::optional(0));

    auto result2 = sequential_search(values, values_len, 5);
    assert(result2 == std::optional(5));

    auto result3 = sequential_search(values, values_len, 9);
    assert(result3 == std::optional(9));
    
    auto result4 = sequential_search(values, values_len, 15);
    assert(!result4.has_value());

    auto result5 = sequential_search(values, values_len, 20);
    assert(!result5.has_value());

    std::cout << "Success!\n";
    return 0;
}
