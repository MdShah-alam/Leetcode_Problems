#include<bits/stdc++.h>
using namespace std;

bool cycle(int i, vector<vector<int>>&adj, vector<int>&visited, vector<int>&pathVis)
{
    visited[i]=1;
    pathVis[i]=1;

    for(int x : adj[i]){
        if(!visited[x]){
            if(cycle(x,adj, visited, pathVis))
                return true;
        }
        else if(pathVis[x])
            return true;
    }
    pathVis[i]=0;
    return false;
}
bool canFinish(int n, vector<vector<int>>& v)
{
    vector<vector<int>>adj(n);
    vector<int>visited(n,0);
    vector<int>pathVis(n,0);

    for(auto & edge : v){
        adj[edge[1]].push_back(edge[0]);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            if(cycle(i,adj,visited,pathVis))
                return false;
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++)
            cin>>v[i][j];
    }
    cout<<canFinish(n,v)<<endl;
    return 0;
}
/**

2 2
1 0
0 1

2 1
1 0

*/
