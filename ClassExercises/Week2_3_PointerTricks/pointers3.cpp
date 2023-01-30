#include <iostream>
using namespace std;

int main() {
    int x = 1;
    int y = 2;
    int *p1 = NULL;
    int *p2 = NULL;
    p1 = &y;
    p2 = &y;
    *p1 = 172;
    *p2 = 7;
    cout << x + y << "\n";
    return 0;
}
