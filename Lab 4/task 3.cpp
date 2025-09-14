#include "iostream"
using namespace std;
void selectionSort(int *array, int size){
    for(int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}
int main(){
    int n;
    cout << "Enter sizew of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter " << n << " inteGers: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; 
    return 0;
}
