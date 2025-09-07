#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList{
public:
    Node* head;
    LinkedList():head(nullptr) {}

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

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    static Node* mergeSorted(Node* l1, Node* l2){
        if (!l1) return l2;
        if (!l2) return l1;
        Node* mergedHead = nullptr;
        if(l1->data < l2->data){
            mergedHead = l1;
            l1 = l1->next;
        }
        else{
            mergedHead = l2;
            l2 = l2->next;
        }
        Node* curr = mergedHead;
        while(l1 && l2){
            if(l1->data < l2->data)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        return mergedHead;
    }
};
int main(){
    LinkedList listA, listB;
    int n1, n2, val;
    cout << "Enter number of elementsin List A: ";
    cin >> n1;
    cout << "Enter elements of List A (sorted): ";
    for(int i = 0; i < n1; i++){
        cin >> val;
        listA.insert(val);
    }
    cout << "Enter numb of elemnts in List B: ";
    cin >> n2;
    cout << "Enter elements ofList B (sorted): ";
    for(int i = 0; i < n2; i++){
        cin >> val;
        listB.insert(val);
    }
    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();
    Node* mergedHead = LinkedList::mergeSorted(listA.head, listB.head);
    cout << "Merged List: ";
    LinkedList mergedList;
    mergedList.head = mergedHead;
    mergedList.display();
    return 0;
}
