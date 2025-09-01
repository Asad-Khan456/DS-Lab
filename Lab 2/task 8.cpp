#include <iostream>
using namespace std;
int main(){
    int days, times;
    cout << "Enter number of days: ";
    cin >> days;
    cout << "Enter No. of readings per day: ";
    cin >> times;
    double** temps = new double*[days];
    for(int i = 0; i < days; i++){
        temps[i] = new double[times];
    }
    for(int i = 0; i < days; i++){
        cout << "Enter temperatures for Day " << i + 1 << ":\n";
        for(int j = 0; j < times; j++){
            cout << "Reading " << j + 1 << ": ";
            cin >> temps[i][j];
        }
    }
    double* dailyAvg = new double[days];
    for(int i = 0; i < days; i++){
        double sum = 0;
        for(int j = 0; j < times; j++){
            sum += temps[i][j];
        }
        dailyAvg[i] = sum / times;
    }
    int hottestDay = 0, coldestDay = 0;
    for(int i = 1; i < days; i++){
        if (dailyAvg[i] > dailyAvg[hottestDay]) hottestDay = i;
        if (dailyAvg[i] < dailyAvg[coldestDay]) coldestDay = i;
    }
    cout << "\nDaily avg temperatures:\n";
    for(int i = 0; i < days; i++){
        cout << "Day " << i + 1 << ": " << dailyAvg[i] << endl;
    }
    cout << "Hottest day: Day " << hottestDay + 1 
         << " (Avg = " << dailyAvg[hottestDay] << ")" << endl;
    cout << "Coldest day: Day " << coldestDay + 1 
         << " (Avg = " << dailyAvg[coldestDay] << ")" << endl;
    for(int i = 0; i < days; i++){
        delete[] temps[i];
    }
    delete[] temps;
    delete[] dailyAvg;
    return 0;
}
