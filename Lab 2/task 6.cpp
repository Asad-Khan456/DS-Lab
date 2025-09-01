#include <iostream>
using namespace std;
class SafePointer{
private:
    int* ptr;
public:
    SafePointer(): ptr(nullptr){}
    void setValue(int value){
        if(ptr == nullptr){
            ptr = new int;
        }
        *ptr = value;
    }
    int getValue() const{
        if(ptr == nullptr){
            cout << "Pointer is null!" << endl;
            return 0;
        }
        return *ptr;
    }
    void release(){
        delete ptr;
        ptr = nullptr;
    }
    ~SafePointer(){
        release();
    }
};
int main(){
    const int n = 5;
    SafePointer students[n];
    cout << "Enter mark for " << n << " students:\n";
    for(int i = 0; i < n; i++){
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        students[i].setValue(mark);
    }
    cout << "Marks of students:\n";
    for(int i = 0; i < n; i++){
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }
    return 0;
}
