#include <stdio.h>
int main() {
    char x[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    printf("%s\n", x);
    printf("  x    = %u\n", x);
    printf(" x+11  = %u\n", x+11);
    printf("&x[11] = %u\n", &x[11]);
    return 0;
}