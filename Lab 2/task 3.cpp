#include <iostream>
using namespace std;


int main(){
    int students;
    cout << "Enter No. of students: ";
    cin >> students;
    int** marks = new int*[students];
    int* courses = new int[students];
    for(int i = 0; i < students; i++){
        cout << "Enter number of courses for student" << i + 1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];
        cout << "Enter marks for " << courses[i] << " courses:\n";
        for(int j = 0; j < courses[i]; j++){
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
    cout << "Avg marks of each student:\n";
    for(int i = 0; i <students; i++){
        int sum = 0;
        for(int j = 0; j < courses[i]; j++){
            sum += marks[i][j];
        }
        double avg = (courses[i] > 0) ? (double)sum / courses[i] : 0.0;
        cout << "Student " << i + 1 << ":" << avg << endl;
    }
    for(int i = 0; i < students; i++){
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;
    return 0;
}
