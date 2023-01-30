#include <iostream>
using namespace std;

int main() {
    int arr[5] = {100, 200, 500, 1000, 2000};
    int x = *(arr+4);
    cout << x << "\n";
    return 0;
}
