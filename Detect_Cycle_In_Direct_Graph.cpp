#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>adj[N];
int visited[N], parent[N];

bool bfs(int src, vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent) {
    visited[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int adj_node : adj[node]) {
            if (!visited[adj_node]) {
                visited[adj_node] = 1;
                parent[adj_node] = node;
                q.push(adj_node);
            }
            else if (parent[node] != adj_node) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool found = false;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(dfs(i)){
                found=true;
                break;
            }
        }
    }
    cout<<found<<endl;
    return 0;
}
