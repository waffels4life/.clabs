#include <stdio.h>
#include <stdint.h>

void draw_rectangle(int8_t rows, int8_t cols);

int main(void) {
    draw_rectangle(5, 16);
    return 0;
}

void draw_rectangle(const int8_t rows, const int8_t cols) {
    for (int8_t row = 0; row < rows; row++) {
        for (int8_t col = 0; col < cols; col++) {
            putchar('*');
        }
        putchar('\n');
    }
}