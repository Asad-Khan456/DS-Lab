#include "iostream"
using namespace std;
int interpoltionSearch(int arr[], int n, int target){
    int low = 0, high = n - 1;
    while(low <= high && target >= arr[low] && target <= arr[high]){
        if(low == high){
            if(arr[low] == target){
                return low;
            }
            else{
                return -1;
            }
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if(arr[pos] == target){
            return pos;
        }
        else if (arr[pos] < target){
            low = pos + 1;
        }
        else{
            high = pos - 1;
        }
    }
    return -1;
}
int main(){
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " sorted integers: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter value to search: ";
    cin >> target;
    int index = interpoltionSearch(arr, n, target);
    if(index != -1){
        cout << "Element found at index: " << index << endl;
    }
    else{
        cout << "Element not found in the array." << endl;
    }
    delete[] arr;
    return 0;
}
