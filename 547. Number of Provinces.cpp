#include<bits/stdc++.h>
using namespace std;

void dfs(int s,int n, vector<bool>&vis , vector<vector<int>>v)
{
    vis[s]=true;
    vector<int>adj;

    for(int i=0;i<n;i++){
        int x=v[s][i];
        if(x==1)
            adj.push_back(i);
    }
    for(auto x:adj){
        if(!vis[x])
            dfs(x,n,vis,v);
    }
}

int findCircleNum(vector<vector<int>>& v)
{
    vector<bool>vis;
    int n=v.size();
    vis.resize(n,false);
    int cont=0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            cont++;
            dfs(i,n,vis,v);
        }
    }
    return cont;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;

    for(int i=0;i<n;i++){
        vector<int>vv;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            vv.push_back(a);
        }
        v.push_back(vv);
    }
    cout<<endl;
    cout<<findCircleNum(v)<<endl;
    return 0;
}/**

3
1 1 0
1 1 0
0 0 1

*/
