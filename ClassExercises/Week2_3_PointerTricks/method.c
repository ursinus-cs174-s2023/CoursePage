#include <stdio.h>

void foo(int param) {
    param = 274;
}

int main() {
    int x = 174;
    foo(x);
    printf("%i\n", x);
    return 0;
}