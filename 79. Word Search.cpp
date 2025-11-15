#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>board, string word, int i, int j, int k)
{
    if(k==word.size()) return true;
    if(i<0||j<0 ||i>=board.size()||j>=board[0].size()||board[i][j]!=word[k])
        return false;
    char temp = board[i][j];
    board[i][j]='*';
    bool isFound = dfs(board,word,i+1,j,k+1)||dfs(board,word,i-1,j,k+1)||dfs(board,word,i,j+1,k+1)||dfs(board,word,i,j-1,k+1);
    board[i][j]=temp;
    return isFound;
}
bool exist(vector<vector<char>>& board, string word)
{
    int n = board.size();
    int m = board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0] && dfs(board,word,i,j,0))
                return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    string s;
    cin>>s;
    cout<<exist(v,s)<<endl;
    return 0;
}
/**

4 3
A B C E
S F C S
A D E E
SEE

*/
