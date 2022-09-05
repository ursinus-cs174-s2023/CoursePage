#include <stdio.h>

// Passing param "by value"
void foo(int* paramAddr) {
    *paramAddr = 274;
}

int main() {
    int x = 174;
    printf("Memory address of x: %u\n", &x);
    int* xaddr = &x;
    foo(xaddr);
    printf("%i\n", x);
    return 0;
}