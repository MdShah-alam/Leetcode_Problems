#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int>adj[],int src,vector<int>&visited)
{
    queue<int>q;
    q.push(src);
    visited[src]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int x = visited[node];
        for(int adj_node : adj[node]){
            if(visited[adj_node]==-1){
                visited[adj_node] = 1 - visited[node];
                q.push(adj_node);
            }
            else if(visited[adj_node]== x)
                return false;
        }
    }
    return true;
}

bool isBipartite(int n,vector<vector<int>>&v)
{
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    vector<int>visited(n);
    for(int i=0;i<n;i++)
        visited[i]=-1;

    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            if(!bfs(adj,i,visited))
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<isBipartite(n,v)<<endl;
    return 0;
}
/**

4
0 3
1 2
3 2
0 2

 */
