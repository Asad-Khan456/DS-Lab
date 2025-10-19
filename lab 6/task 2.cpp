#include <iostream>
#include "string"
using namespace std;
class Node{
public:
    string data;
    Node* next;
    Node(string value){
        data = value;
        next = nullptr;
    }
};
class Stack{
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        while(top != nullptr){
            pop();
        }
    }
    void push(string value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << value << endl;
    }


    void pop(){
        if (top == nullptr){
            cout << "No previous pages." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "going back from: " << temp->data << endl;
        delete temp;
    }
    void peek(){
        if(top == nullptr)
        {
            cout << "No current page." << endl;
        }
        else
        {
            cout << "Current page: " << top->data << endl;
        }
    }
    void display(){
        if(top == nullptr){
            cout << "No browsing history." << endl;
            return;
        }
        Node* temp = top;
        cout << "Browsing history:" << endl;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main(){
    Stack browserHistory;
    browserHistory.push("youtube.com");
    browserHistory.push("github.com");
    browserHistory.push("google.com");
    browserHistory.peek();
    browserHistory.display();
    browserHistory.pop();
    browserHistory.peek();
    browserHistory.pop();
    browserHistory.peek();
    browserHistory.display();
    return 0;


}




