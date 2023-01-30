#include <iostream>
using namespace std;

void printString(char* s) {
    while (*s != '\0') {
        cout << *s << "\n";
        s++;
    }
}

int main() {
    char x[12] = {'H', 'e', 'l', 'l', 'o', '\0', 'w', 'o', 'r', 'l', 'd', '\0'};
    cout << x << "\n";
    //printString(x);
    //printf("  x    = %u\n", x);
    /*printf(" x+11  = %u\n", x+11);
    printf("&x[11] = %u\n", &x[11]);*/
    return 0;
}