#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int* array = new int[size];
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
    char choice;
    do{
        int index, value;
        cout << "Enter index (0 - " << size - 1 << "): ";
        cin >> index;
        if(index < 0 || index >= size){
            cout << "Invald index!" << endl;
        }
        else{
            cout << "Enter value to assign at index " << index << ": ";
            cin >> value;
            array[index] = value;
        }

        cout << "Do you want to update another value?: \ny for yes, n for no:";
        cin >> choice;
    }while(choice == 'y'|| choice =='Y');
    cout << "Final array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
    return 0;
}
