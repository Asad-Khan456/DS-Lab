#include <iostream>
using namespace std;
class CircularQueue{
    int *arr;
    int front, rear, size, count;
public:
    CircularQueue(int capacity){
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~CircularQueue(){
        delete[] arr;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == size;
    }
    void enqueue(int value){
        if(isFull()){
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = value;
            count++;
            cout << value << " enqueued." << endl;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
        else{
            cout << arr[front] << " dequeued." << endl;
            front = (front + 1) % size;
            count--;
        }
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue contents: ";
            for(int i = 0; i < count; i++)
            {
                int index = (front + i) % size;
                cout << arr[index] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    if(q.isFull()){
        cout << "Queue is full." << endl;
    }
    else{
        cout << "Queue is not full." << endl;
    }
    if(q.isEmpty()){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Queue is not empty." << endl;
    }

    return 0;


}
