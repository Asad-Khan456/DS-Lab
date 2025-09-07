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
    Node* reverseInGroupsUtil(Node* head, int k) {
        if(!head) return nullptr;
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;
        while(curr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next)
            head->next = reverseInGroupsUtil(next, k);

        return prev;
    }
public:
    LinkedList() : head(nullptr) {}
    void insert(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void reverseInGroups(int k){
        head = reverseInGroupsUtil(head, k);
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
    int n, val, k;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> val;
        list.insert(val);
    }
    cout << "Enter group size k: ";
    cin >> k;
    cout << "Original List: ";
    list.display();
    list.reverseInGroups(k);
    cout << "Reversed in groups of " << k << ": ";
    list.display();

    return 0;
}
