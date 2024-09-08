#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>&grid,const int &i,const int &j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
        return ;
    grid[i][j]='s';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
int numIslands(vector<vector<char>>& grid)
{
    if(grid.empty()) return 0;
    int cont{0};
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                cont++;
                dfs(grid,i,j);
            }
        }
    }
    return cont;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>vv;

    for(int i=0;i<n;i++){
        vector<char>v;
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            v.push_back(a);
        }
        vv.push_back(v);
    }
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<numIslands(vv)<<endl;
    return 0;
}
/**

4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0

grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
*/
