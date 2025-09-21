#include <iostream>
using namespace std;

class Factorial {
public:
    int calculateFactorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * calculateFactorial(n - 1);
    }
};

int main() {
    Factorial f;
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Factorial of " << number << " = " 
         << f.calculateFactorial(number) << endl;
    return 0;
}
