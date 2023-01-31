#include <iostream>
using namespace std;

int main() {
    long arr[5] = {100, 200, 500, 1000, 2000};
    int length = 5;
    long x = *(arr+1000000); // "Pointer arithmetic"
    // When we add a number to a polonger, it actually
    // moves us by sizeof(long)
    // x + k, is equivalent to the address
    // x + k*sizeof(long)
    cout << "sizeof(long) " << sizeof(long) << "\n";
    cout << x << "\n";
    return 0;
}
