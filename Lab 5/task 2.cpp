#include <iostream>
using namespace std;

// Direct Recursion
void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    printNumbers(n - 1);
}

// Indirect Recursion
void functionB(int n); 

void functionA(int n) {
    if (n <= 0) {
        return;
    }
    cout << "A: " << n << " ";
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) {
        return;
    }
    cout << "B: " << n << " ";
    functionA(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "\nDirect Recursion (numbers from " << num << " down to 1):\n";
    printNumbers(num);

    cout << "\n\nIndirect Recursion (alternating A and B calls):\n";
    functionA(num);

    cout << endl;
    return 0;
}
