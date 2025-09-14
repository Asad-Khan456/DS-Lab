#include "iostream"
using namespace std;
void bubbleSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = swaps = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            comparisons++;
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}
void insertionSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = swaps = 0;
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            comparisons++;
            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else{
                break;
            }
        }
        arr[j + 1] = key;
    }
}
void shellSort(int arr[],int n,int &comparisons,int &swaps){
    comparisons = swaps = 0;
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if(arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                }
                else{
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int* arr = new int[n];
    int* arrCopy1 = new int[n];
    int* arrCopy2 = new int[n];
    cout << "Enter " << n << " integers:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arrCopy1[i] = arr[i];
        arrCopy2[i] = arr[i];
    }
    int comparisons, swaps;
    bubbleSort(arr, n, comparisons, swaps);
    cout << "\nBubble Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    insertionSort(arrCopy1, n, comparisons, swaps);
    cout << "Insertion Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    shellSort(arrCopy2, n, comparisons, swaps);
    cout << "Shell Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    delete[] arr;
    delete[] arrCopy1;
    delete[] arrCopy2;
    return 0;
}
