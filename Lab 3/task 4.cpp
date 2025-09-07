#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {
    }
    void create(int n){
        if(n <= 0) return;
        head = new Node(1);
        Node* prev = head;
        for(int i = 2; i <= n; i++){
            Node* newNode = new Node(i);
            prev->next = newNode;
            prev = newNode;
        }
        prev->next = head; 
    }
    int josephus(int k){
        if (!head || k <= 0) return -1;
        Node* curr = head;
        Node* prev = nullptr;
        while (curr->next != curr){
            for(int count = 1; count < k; count++){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        int survivor = curr->data;
        delete curr;
        return survivor;
    }
};
int main(){
    int N, k;
    cout << "Enter no. of people (N): ";
    cin >> N;
    cout << "Enter step count (k): ";
    cin >> k;
    CircularLinkedList cll;
    cll.create(N);
    int survivor = cll.josephus(k);
    cout << "The survivor is at position: " << survivor << endl;
    return 0;
}
