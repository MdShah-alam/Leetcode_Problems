#include<bits/stdc++.h>
using namespace std;
const int n=9;

bool isvalid(vector<vector<char>>& board, int row, int col , char num)
{
    for(int i=0;i<n;i++){
        if(board[row][i]==num || board[i][col]==num)
            return false;
    }
    int r=(row/3)*3;
    int c=(col/3)*3;

    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(board[i][j]==num)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>&board)
{
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]=='.'){
                for(char num='1';num<='9';num++){
                    if(isvalid(board,row,col,num)){
                        board[row][col]=num;
                        if(solve(board))
                            return true;

                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board)
{
    solve(board);
}

int main()
{
    vector<vector<char>>sudoku_board(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>sudoku_board[i][j];
    }
    cout<<endl;
    solveSudoku(sudoku_board);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<sudoku_board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

/**

5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

*/
