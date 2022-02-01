#include <stdio.h>



int main() {
    int x = 1;
    int y = 2;
    int *p1 = NULL;
    int *p2 = NULL;
    p1 = &y;
    p2 = &y;
    *p1 = 172;
    *p2 = 7;
    printf("%i\n", x+y);
    return 0;
}