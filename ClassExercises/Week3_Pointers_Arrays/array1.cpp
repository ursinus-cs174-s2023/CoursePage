#include <iostream>
using namespace std;
int main() {
    int arr[4] = {100, 200, 500, 1000};
    int* ptr = arr;
    cout << *ptr << "\n";
    return 0;
}
