#include <iostream>
using namespace std;

int main() {
    int arr[5] = {100, 200, 500, 1000, 2000};
    cout << &arr[4] - arr << "\n";
    cout << "arr     = " << (uint64_t)arr << "\n";
    cout << "&arr[4] = " << (uint64_t)&arr[4] << "\n";
    return 0;
}