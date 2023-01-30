#include <iostream>
using namespace std;

int main() {
    int arr[5] = {100, 200, 500, 1000, 2000};
    cout << (uint64_t)arr << "\n";
    cout << (uint64_t)&arr[4] << "\n";
    return 0;
}
