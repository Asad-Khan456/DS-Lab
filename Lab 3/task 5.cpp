#include <iostream>
using namespace std;
class SingleNode{
public:
    int data;
    SingleNode* next;
    SingleNode(int val) : data(val), next(nullptr) {
    }
};
class DoubleNode{
public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class SingleLinkedList{
public:
    SingleNode* head;
    SingleLinkedList(): head(nullptr){
    }
    void insert(int val){
        SingleNode* newNode = new SingleNode(val);
        if(!head){
            head = newNode;
            return;
        }
        SingleNode* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void display(){
        SingleNode* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    DoubleNode* toDoubleLinkedList(){
        if(!head) return nullptr;
        SingleNode* curr = head;
        DoubleNode* dHead = new DoubleNode(curr->data);
        DoubleNode* dCurr = dHead;
        curr = curr->next;
        while(curr){
            DoubleNode* newNode = new DoubleNode(curr->data);
            dCurr->next = newNode;
            newNode->prev = dCurr;
            dCurr = newNode;
            curr = curr->next;
        }
        return dHead;
    }
    SingleNode* toCircularLinkedList(){
        if(!head) return nullptr;
        SingleNode* curr = head;
        while(curr->next)
            curr = curr->next;
        curr->next = head;
        return head;
    }
};

class DoubleLinkedList{
public:
    DoubleNode* head;
    DoubleLinkedList() :head(nullptr) {
    }
    void setHead(DoubleNode* node){
        head = node;
    }
    void display(){
        DoubleNode* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class CircularLinkedList{
public:
    SingleNode* head;
    CircularLinkedList() :head(nullptr) {
    }
    void setHead(SingleNode* node){
        head = node;
    }
    void display(int n){
        if (!head) return;
        SingleNode* temp = head;
        for(int i = 0; i < n; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    SingleLinkedList sList;
    int n, val;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        sList.insert(val);
    }
    cout << "Single Linked List: ";
    sList.display();
    DoubleLinkedList dList;
    dList.setHead(sList.toDoubleLinkedList());
    cout << "ConvertedDouble Linked List: ";
    dList.display();
    CircularLinkedList cList;
    cList.setHead(sList.toCircularLinkedList());
    cout << "Convrted Circular Linked List (first " << n*2 << " nodes): ";
    cList.display(n * 2);
    return 0;
}
