#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j,int n, int m ,vector<vector<char>>&v,vector<vector<int>>&visited)
{
    if(i<0 || j<0 || i>=n || j>=m || v[i][j]=='0' || visited[i][j]==1)
        return ;
    visited[i][j]=1;
    dfs(i+1,j,n,m,v,visited);
    dfs(i-1,j,n,m,v,visited);
    dfs(i,j+1,n,m,v,visited);
    dfs(i,j-1,n,m,v,visited);
}

int countIslands(vector<vector<char>>&v)
{
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>>visited(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visited[i][j]=0;
    }
    int cont =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='1' && visited[i][j]!=1){
                dfs(i,j,n,m,v,visited);
                cont++;
            }
        }
    }
    return cont;
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
    cout<<numIslands(v)<<endl;
}

/**

5 4
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

*/
