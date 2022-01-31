#include <stdio.h>


int main() {
    int arr[4] = {100, 200, 500, 1000};
    int x = *(arr+2);
    printf("%i\n", x);
    return 0;
}
