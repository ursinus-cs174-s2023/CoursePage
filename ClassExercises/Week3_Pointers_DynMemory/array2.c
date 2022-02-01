#include <stdio.h>


int main() {
    int N = 10;
    int* arr = new int[N];
    
    delete[] arr;
    return 0;
}
