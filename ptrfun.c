#include <stdio.h>
#include <stdlib.h>

// The Core Idea: Functions Live in Memory Too.
// Every function you write is compiled into machine code that sits somewhere in memory.
// That means a function has an address — just like a variable.

int ascending(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int descending(const void *a, const void *b) {
    return (*(int*)b) - (*(int*)a);
}

int add(const int a, const int b) { return a + b; }
int sub(const int a, const int b) { return a - b; }
int mul(const int a, const int b) { return a * b; }
int dvd(const int a, const int b) { return b ? a / b : 0; }

void on_state(void) { printf("ON\n"); }
void off_state(void) { printf("OFF\n"); }

void (*next_state(const int current))(void) {
    return current ? off_state : on_state;
}

int ptr_function_behavior(void) {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), ascending);
    qsort(arr, n, sizeof(int), descending);

    int (*ops[4])(int, int) = { add, sub, mul, dvd };

    for (int i = 0; i < 4; i++) {
        const char *names[4] = { "add", "sub", "mul", "div" };
        printf("%s(8,2) = %d\n", names[i], ops[i](8, 2));
    }

    void (*state)(void) = on_state;
    for (int i = 0; i < 4; i++) {
        state();
        state = next_state(state == on_state);
    }
    return 0;
}
