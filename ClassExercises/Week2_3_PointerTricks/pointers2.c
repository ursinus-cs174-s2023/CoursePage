#include <stdio.h>


int main() {
    int x = 1;
    int y = 2;
    int *p1 = NULL;
    int *p2 = NULL;
    p2 = &y;
    *p1 = 170;
    *p2 = 4;
    printf("%i\n", x+y);
    return 0;
}
