#include <stdio.h>


#include <stdio.h>
int main() {
    int arr[5] = {100, 200, 500, 1000, 2000};
    printf("%i\n", &arr[4] - arr);
    printf("arr = %u\n", arr);
    printf("&arr[4] = %u\n", &arr[4]);
    return 0;
}