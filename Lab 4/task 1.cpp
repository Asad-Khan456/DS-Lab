#include "iostream"
using namespace std;

int main(){
    int n;
    int Tvalue;
    cout << "input size oif aray" << endl;
    cin >> n;
    int arr[n];
    cout << "INput Elements in array" << endl;
    for(int i=0;i < n;i++){
        cin >> arr[i];
    }
    cout << " Enter The value you want to search " << endl;
    cin >> Tvalue;
    int index = -1;
    for(int k=0;k<n;k++){
        if(arr[k] == Tvalue)
        {
            index = k;
            break;
        
        }
    }
    if(index == -1){
        cout << " Element not foumd" << endl;

    }
    else
    {
        cout << "Element found at Index:" << index << endl;

    }
    return 0;
}
