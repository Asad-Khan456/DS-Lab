#include <iostream>
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter number of rows:";
    cin >> rows;
    cout << "Enter number of columns;";
    cin >> cols;
    int** A = new int*[rows];
    int** B = new int*[rows];
    int** sum = new int*[rows];
    int** diff = new int*[rows];
    for(int i = 0; i < rows; i++){
        A[i] = new int[cols];
        B[i] = new int[cols];
        sum[i] = new int[cols];
        diff[i] = new int[cols];
    }
    cout << "Enter elements of Matrix A:";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }
    cout << "Enter elements of Matrix B:";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> B[i][j];
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "Matrix A:\n";
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << A[i][j] << " ";1
        }
        cout << endl;
    }
    cout << "Matrix B:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << "A + B:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << "A - B:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < rows; i++){
        delete[] A[i];
        delete[] B[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] A;
    delete[] B;
    delete[] sum;
    delete[] diff;
    return 0;
}
