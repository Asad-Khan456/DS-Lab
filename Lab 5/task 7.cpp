#include <iostream>
#include <vector>
using namespace std;


class NQueens{
    int N;
    bool isSafe(vector<vector<int>>& board, int row, int col){
        for(int i = 0; i < row; i++){
            if (board[i][col] == 1)
            {
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1)
            {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++){
            if(board[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }


    void solveNQUtil(vector<vector<int>>& board, int row){
        if(row == N){
            printSolution(board);
            return;
        }
        for(int col = 0; col < N; col++){
            if(isSafe(board, row, col)){
                board[row][col] = 1;
                solveNQUtil(board, row + 1);
                board[row][col] = 0;
            }
        }
    }
    void printSolution(vector<vector<int>>& board){
        static int solutionCount = 1;
        cout << "Solution " << solutionCount++ << ":\n";
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    NQueens(int n) : N(n){}
    void solve(){
        vector<vector<int>> board(N, vector<int>(N, 0));
        solveNQUtil(board, 0);
    }
};
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    NQueens nq(n);
    nq.solve();
    return 0;
}
