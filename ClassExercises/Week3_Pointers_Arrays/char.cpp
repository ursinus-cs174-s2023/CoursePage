#include <iostream>
using namespace std;

/*
Print out the character array
without using *any* array 
indexing x[i]

Are allowed: pointer arithmetic
and dereferencing
*/
void printArray(char* x) {
    while (*x != '\0') {
        cout << *x;
        x++;
    }
}

int main() {
    char x[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
    // Null terminator: '\0'
    /*int i = 0;
    while (x[i] != '\0') {
        cout << x[i];
        i++;
    }
    cout << "\n";*/
    printArray(x);
    cout << "\n";
    return 0;
}