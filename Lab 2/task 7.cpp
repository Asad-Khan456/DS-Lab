#include <iostream>
using namespace std;
int main(){
    int departments;
    cout << "Enter num of departments: ";
    cin >> departments;
    int** salaries = new int*[departments];
    int* employees = new int[departments];
    for(int i = 0; i < departments; i++){
        cout << "Enter number of employees in department " << i + 1 << ": ";
        cin >> employees[i];


        salaries[i] = new int[employees[i]];
        cout << "Enter salaries of " << employees[i] << " employees:\n";
        for(int j = 0; j < employees[i]; j++){
            cout << "Employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }
    cout << "Highest salary in each department:\n";
    for(int i = 0; i < departments; i++){
        int maxSalary = salaries[i][0];
        for(int j = 1; j < employees[i]; j++){
            if(salaries[i][j] > maxSalary){
                maxSalary = salaries[i][j];
            }
        }
        cout << "Depaartment " << i + 1 << ": " << maxSalary << endl;
    }
    int bestDept = 0;
    double maxAvg = 0.0;
    for(int i = 0; i < departments; i++){
        int sum = 0;
        for(int j = 0; j < employees[i]; j++){
            sum += salaries[i][j];
        }
        double avg = (employees[i] > 0) ? (double)sum / employees[i] : 0.0;
        if(avg > maxAvg){
            maxAvg = avg;
            bestDept = i;
        }
    }
    cout << "Department with highest avg salary: Department " << bestDept + 1 << " (Average = " << maxAvg << ")" << endl;
    for(int i = 0; i < departments; i++){
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] employees;
    return 0;
}
