#include "iostream"
using namespace std;
int main(){
    int n;
    cout << "input size oif aray" << endl;
    cin >> n;
    int arr[n];
    cout << "INput Elements in array" << endl;
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        for(int k=0; k< n-i-1; k++)
        {
            if(arr[k] > arr[k+1])
            {
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr [k+1] = temp;

            }
        }
    }
    cout << "Sorted Array" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
