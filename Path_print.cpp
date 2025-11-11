#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>adj[N];
int visited[N],parent[N];

void bfs(int src)
{
    visited[src] = 1;
    parent[src] = 0;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int adj_node : adj[node]){
            if(!visited[adj_node]){
                parent[adj_node]=node;
                visited[adj_node]=1;
                q.push(adj_node);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    int des=6;
    while(parent[des]){
        cout<<parent[des]<<" ";
        des = parent[des];
    }
    cout<<endl;
}
/**

6 6
1 2
1 3
2 5
3 4
4 5
4 6


*/
