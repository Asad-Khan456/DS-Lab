#include <iostream>
using namespace std;


int sumTail(int n, int total){
    if(n == 0){
        return total;
    }
    return sumTail(n - 1, total + n);
}
int sumNonTail(int n){
    if(n == 0){
        return 0;
    }
    return n + sumNonTail(n - 1);
}
int main(){
    int num;
    cout << "Enter a num:";
    cin >> num;
    cout << "Sum using Tail rceursion: " << sumTail(num, 0) << endl;
    cout << "Sum using Non Tail recursion: " << sumNonTail(num) << endl;
    return 0;
}
