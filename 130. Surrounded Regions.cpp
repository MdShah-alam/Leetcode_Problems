#include<bits/stdc++.h>
using namespace std;

void capture(int i, int j, vector<vector<char>>&board)
{
    if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!='O')
        return ;
    board[i][j]='T';
    capture(i+1,j,board);
    capture(i-1,j,board);
    capture(i,j+1,board);
    capture(i,j-1,board);
}
void solve(vector<vector<char>>& board)
{
    int n=board.size();
    int m=board[0].size();

    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O') capture(i, 0, board);
        if (board[i][m - 1] == 'O') capture(i, m - 1, board);
    }
    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O') capture(0, j, board);
        if (board[n - 1][j] == 'O') capture(n - 1, j, board);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j]=='O')
                board[i][j]='X';
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(board[i][j]=='T')
                board[i][j]='O';
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>v[i][j];
        }
    }

    solve(v);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/**

4 4
X X X X
X O O X
X X O X
X O X X

*/

