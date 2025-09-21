#include <iostream>
using namespace std;

// Tail Recursion
int sumTail(int n, int total) {
    if (n == 0) {
        return total;
    }
    return sumTail(n - 1, total + n);
}

// Non-Tail Recursion
int sumNonTail(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumNonTail(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Sum using Tail Recursion: " << sumTail(num, 0) << endl;
    cout << "Sum using Non-Tail Recursion: " << sumNonTail(num) << endl;

    return 0;
}
