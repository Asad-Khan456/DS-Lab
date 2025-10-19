#include <iostream>
using namespace std;
class Stack{
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack(){
        delete[] arr;
    }
    void push(int x){
        if(top == capacity - 1){
            cout << "Stack Overflow: cant push " << x << ",stack is full." << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed to stack." << endl;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow:stack is empty." << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void peek(){
        if(top == -1){
            cout << "Stack is empty." << endl;
        }
        else{
            cout << "top element is: " << arr[top] << endl;
        }
    }
    void display(){
        if(top == -1){
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack contents: ";
            for(int i = 0; i <= top; ++i){
                cout << arr[i] << " ";
            }

            cout << "\n";
        }
    }
};
int main(){
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.display();
    stack.peek();
    stack.pop();
    stack.pop();
    stack.display();
    stack.peek();
    return 0;
}

