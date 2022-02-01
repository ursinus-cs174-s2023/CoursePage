#include <stdio.h>


int main() {
    int arr[5] = {100, 200, 500, 1000, 2000};
    int x = *(arr+4);
    printf("%i\n", x);
    return 0;
}
