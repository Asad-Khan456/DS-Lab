#include "iostream"
using namespace std;
class Queue{
    int *arr;
    int front, rear, capacity;
public:
    Queue(int size){
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    ~Queue(){
        delete[] arr;
    }
    bool isEmpty(){
        return front > rear;
    }
    bool isFull(){
        return rear == capacity - 1;
    }
    void enqueue(int value){
        if(isFull()){
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
        }
        else{
            arr[++rear] = value;
            cout << value << " enqueued." << endl;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
        else {
            cout << arr[front++] << " dequeued." << endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "queue contents: ";
            for(int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    if(q.isEmpty())
    {
        cout << "queue is empty." << endl;
    }
    else{
        cout << "Queue is not empty." << endl;
    }
    if(q.isFull()){
        cout << "Queue is full." << endl;
    }
    else{
        cout << "Queue is not full." << endl;
    }


    return 0;


}





