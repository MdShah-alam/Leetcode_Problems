#include<bits/stdc++.h>
using namespace std;
const int n=9;

bool isValidSudoku(vector<vector<char>>& board)
{
    // Hash sets to keep track of seen numbers in rows, columns, and 3x3 sub-boxes
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    // Traverse the board
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            char num = board[row][col];

            // Skip empty cells
            if (num == '.') continue;

            // Calculate the index for the 3x3 sub-box
            int boxIndex = (row / 3) * 3 + (col / 3);

            // Check for duplicates in the row, column, or box
            if (rows[row].count(num) || cols[col].count(num) || boxes[boxIndex].count(num))
            {
                return false;
            }

            // Mark the number as seen in the current row, column, and box
            rows[row].insert(num);
            cols[col].insert(num);
            boxes[boxIndex].insert(num);
        }
    }
    return true;
}
int main()
{
    vector<vector<char>>sudoku_board(n,vector<char>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>sudoku_board[i][j];
    }
    cout<<endl<<isValidSudoku(sudoku_board)<<endl;
    return 0;
}

/**

5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9

*/
