#include <iostream>
using namespace std;
void printNumbers(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    printNumbers(n - 1);
}
void functionB(int n); 
void functionA(int n){
    if(n <= 0){
        return;
    }
    cout << "A: " << n << " ";
    functionB(n - 1);
}
void functionB(int n){
    if(n <= 0){
        return;
    }
    cout << "b; "<< n << " ";
    functionA(n - 1);
}
int main(){
    int num;
    cout << "Enter a num: ";
    cin >> num;
    cout << "\nDirect recursion (num from " << num << " down to 1):" << endl;
    printNumbers(num);
    cout << "\n\nIndirect Recursion (alternating a and b calls):" << endl;
    functionA(num);
    cout << endl;
    return 0;
}
