#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>&v, string s, int i,int j, int cont)
{
    if(cont==s.size())
        return true;

    if(i>=v.size()||i<0||j>=v[0].size()||j<0||s[cont]!=v[i][j])
        return false;

    char temp = v[i][j];
    v[i][j]='*';

    bool isFound = dfs(v,s,i+1,j,cont+1)||dfs(v,s,i-1,j,cont+1)||dfs(v,s,i,j+1,cont+1)||dfs(v,s,i,j-1,cont+1);

    v[i][j]=temp;
    return isFound;
}
bool exist(vector<vector<char>>& board, string word)
{
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(word[0]==board[i][j] && dfs(board, word, i,j,0))
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

    string word;
    cin>>word;
    cout<<exist(v,word)<<endl;

    return 0;
}
/**

3 4
A B C E
S F C S
A D E E
ABCCED

3 4
A B C E
S F C S
A D E E
ABCB

*/
