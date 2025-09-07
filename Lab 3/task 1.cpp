#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList{
private:
    Node* head;
    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    LinkedList() : head(nullptr) {    
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    bool isPalindrome(){
        if(!head || !head->next) return true;
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* secondHalf = reverseList(slow->next);
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf;
        bool result = true;
        while(secondHalf){
            if(firstHalf->data != secondHalf->data){
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        slow->next = reverseList(secondHalfCopy);
        return result;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList list;
    int n, val;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        list.insert(val);
    }
    cout << "Linked List: ";
    list.display();
    if(list.isPalindrome())
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
