#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

void draw_rectangle(int8_t rows, int8_t cols);
void minMax(const int ages[], int length, int *min, int *max);

static void circle_area(const float *radius, float *area) {
    if (radius == NULL || area == NULL) return;
    *area = PI * (*radius) * (*radius);
}

int main(void) {
    draw_rectangle(5, 16);

    const int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};
    const int length = sizeof(ages) / sizeof(ages[0]);
    int lowest, highest;

    minMax(ages, length, &lowest, &highest);

    printf("Lowest age: %d\n", lowest);
    printf("Highest age: %d\n", highest);
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

void minMax(const int ages[], const int length, int *min, int *max) {
    *min = ages[0];
    *max = ages[0];
    for (int i = 1; i < length; i++) {
        if (ages[i] < *min) {
            *min = ages[i];
        }
        if (ages[i] > *max) {
            *max = ages[i];
        }
    }
}