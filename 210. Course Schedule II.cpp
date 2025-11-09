#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& v)
{
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    // Build adjacency list and indegree count
    for (auto& edge : v) {
        adj[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
    }

    // Queue for nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    // Kahn’s Algorithm (BFS)
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);

        for (int y : adj[x]) {
            inDegree[y]--;
            if (inDegree[y] == 0)
                q.push(y);
        }
    }
    return n == ans.size() ? ans : vector<int>{};
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
    vector<int>ans = findOrder(n,v);
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
/**

2 2
1 0
0 1

2 1
1 0

*/
