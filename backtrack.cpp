#include <iostream>

void backtrack(int* buffer, int buffer_len, int digit);
void backtrack_inner(int* buffer, int buffer_len, int digit);
void print_buffer(const int* buffer, int buffer_len);

void backtrack(int* buffer, int buffer_len) {
    backtrack_inner(buffer, buffer_len, 0);
}

void backtrack_inner(int* buffer, int buffer_len, int index) {
    if (index >= buffer_len) {
        print_buffer(buffer, buffer_len);
        return;
    }

    for (int i = 0; i <= 9; ++i) {
        buffer[index] = i;
        backtrack_inner(buffer, buffer_len, index + 1); 
    }
}

void print_buffer(const int* buffer, int buffer_len) {
    for (int i = 0; i < buffer_len; ++i) {
        std::cout << buffer[i];
    }

    std::cout << '\n';
}

int main() {
    int buffer[5] = { 0 };
    int buffer_len = sizeof(buffer) / sizeof(int);
    backtrack(buffer, buffer_len);
}
