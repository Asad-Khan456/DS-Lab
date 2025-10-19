#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Process{
    int id;
    int priority;
};
class JobScheduler{
    queue<Process> arrivalQueue;
    stack<Process> execStack;
    int highPriorityThreshold;
public:
    JobScheduler(int threshold){
        highPriorityThreshold = threshold;
    }
    void arrive(Process p){
        arrivalQueue.push(p);
        cout << "Process ID " << p.id << " with priority " << p.priority << " arrived." << endl;
    }
    void prepareExecution(){
        int size = arrivalQueue.size();
        for(int i = 0; i < size; i++){
            Process p = arrivalQueue.front();
            arrivalQueue.pop();
            if(p.priority >= highPriorityThreshold){
                execStack.push(p);
                cout << "Process ID " << p.id << " moved to execution stack (high priority)." << endl;
            }
            else{
                arrivalQueue.push(p);
            }
        }
    }



    void executeAll(){
        cout << "Executing high priority processes (LIFO):" << endl;
        while(!execStack.empty()){
            Process p = execStack.top();
            execStack.pop();
            cout << "Executing Process ID " << p.id << " with priority " << p.priority << endl;
        }

        cout << "Executing remaining processes in arrival order (FIFO):" << endl;
        while(!arrivalQueue.empty()){
            Process p = arrivalQueue.front();
            arrivalQueue.pop();
            cout << "Executing Process ID " << p.id << " with priority " << p.priority << endl;
        }
    }
};
int main(){
    JobScheduler scheduler(5);
    scheduler.arrive({101, 3});
    scheduler.arrive({102, 7});
    scheduler.arrive({103, 5});
    scheduler.arrive({104, 2});
    scheduler.arrive({105, 8});
    scheduler.prepareExecution();


    scheduler.executeAll();
    return 0;


}


