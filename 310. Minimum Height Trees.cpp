#include<bits/stdc++.h>
using namespace std;

vector<int>findMinHeightTrees(int n, vector<vector<int>>&edges)
{
    if(n==1) return {0};
    vector<vector<int>>adj(n);
    vector<int>degree(n,0);
    for(auto &edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(degree[i]==1) q.push(i);
    }
    int remain = n;
    while(remain>2){
        int siz = q.size();
        remain-=siz;
        while(siz--){
            int leaf = q.front();
            q.pop();
            for(int neighbor : adj[leaf]){
                if(--degree[neighbor]==1)
                    q.push(neighbor);
            }
        }
    }
    vector<int>result;
    while(!q.empty()){
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++)
        cin>>v[i][0]>>v[i][1];

    vector<int>k=findMinHeightTrees(n,v);

    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
}
/**

6

3 0
3 1
3 2
3 4
5 4

*/
