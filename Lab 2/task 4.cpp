#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter no. of months to track:";
    cin >> n;
    double* expenses = new double[n];
    for(int i = 0; i < n; i++){
        cout <<"Enter expense for month" << i + 1 << ": ";
        cin >> expenses[i];
    }
    char choice;
    cout << "Do yuo want to add more months?(y/n):";
    cin >> choice;
    if(choice == 'y' ||choice == 'Y'){
        int extra;
        cout <<"How many extra months do you want to add?";
        cin >> extra;
        double* newArray = new double[n + extra];
        for(int i = 0; i < n; i++){
            newArray[i] = expenses[i];
        }
        for(int i = 0; i < extra; i++){
            cout << "Enter expense for month " << n + i + 1 << ": ";
            cin >> newArray[n + i];
        }
        delete[] expenses;
        expenses = newArray;
        n += extra;
    }
    double total = 0;
    for(int i = 0; i < n; i++){
        total += expenses[i];
    }
    double average = (n > 0) ? total / n : 0.0;
    cout << "Total expenses = " << total << endl;
    cout << "Average monthly expense = " << average << endl;
    delete[] expenses;
    return 0;
}
