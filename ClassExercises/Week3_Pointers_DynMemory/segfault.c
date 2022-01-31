#include <stdio.h>


int main() {
    int x = 1;
    int y = 2;
    int *p1 = NULL;
    printf("%u\n", p1);
    int *p2 = NULL;
    p2 = &y;
    *p1 = 170; // Dangerous??
    *p2 = 4;
    printf("%i\n", x+y);
    return 0;
}