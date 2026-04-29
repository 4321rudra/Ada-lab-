#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<char>>& board, int row, int col, int n){
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q')
            return false;
    }
    int i = row - 1;
    int j = col - 1;
    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while(i >= 0 && j < n)
    {
        if(board[i][j] == 'Q')
            return false;
        i--;
        j++;
    }
    return true;
}
void solveNQueens(vector<vector<char>>& board, int row, int n){
    if(row == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "------------------" << endl;
        return;
    }
    for(int col = 0; col < n; col++){
        if(isSafe(board, row, col, n)){
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n);
            board[row][col] = '.';
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    solveNQueens(board, 0, n);
    return 0;
}