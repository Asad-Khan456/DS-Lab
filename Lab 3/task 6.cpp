#include <iostream>
using namespace std;
class MultiNode{
public:
    int data;
    MultiNode* next;
    MultiNode* child;
    MultiNode(int val) : data(val), next(nullptr), child(nullptr){
    }
};
class MultiLevelLinkedList{
public:
    MultiNode* head;
    MultiLevelLinkedList() : head(nullptr){
    }
    void insert(int val){
        MultiNode* newNode = new MultiNode(val);
        if(!head)
        {
            head = newNode;
            return;
        }
        MultiNode* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    MultiNode* getNode(int val){
        MultiNode* temp = head;
        while (temp) {
            if(temp->data == val) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    static MultiNode* flatten(MultiNode* head){
        if(!head) return nullptr;
        MultiNode* curr = head;
        while(curr){
            if(curr->child){
                MultiNode* next = curr->next;
                curr->next = curr->child;
                MultiNode* tail = curr->child;
                while(tail->next)
                    tail = tail->next;
                tail->next = next;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
    void display(){
        MultiNode* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    MultiLevelLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    MultiNode* node2 = list.getNode(2);
    if(node2){
        node2->child = new MultiNode(4);
        node2->child->next = new MultiNode(5);
    }
    cout << "Orignal Top-Level List: ";
    list.display();
    list.head = MultiLevelLinkedList::flatten(list.head);
    cout << "Flatened List: ";
    list.display();
    return 0;
}
