#include <stdio.h>
int main() {
    int x[3];
    x[0] = 2100000007;
    x[1] = 1740000174;
    x[2] = 4200042;
    char* str = (char*)x;
    str[0] = 'h';
    str[1] = 'i';
    printf("%s\n", str);
    printf("x[0] = %i\n", x[0]);
    printf("x[1] = %i\n", x[1]);
    printf("x[2] = %i\n", x[2]);
    return 0;
}