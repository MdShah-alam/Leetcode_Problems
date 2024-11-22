#include<bits/stdc++.h>
using namespace std;

int visited[10000];
vector<int>adj_list[10000];
bool cycle_detected(int node)
{
    visited[node]=1;
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            bool get_cycle=cycle_detected(adj_node);
            if(get_cycle)
                return true;
        }
        else if(visited[adj_node]==1)
            return true;
    }
    visited[node]=2;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    for(auto it : prerequisites)
    {
        int u=it[0];
        int v=it[1];
        adj_list[u].push_back(v);
    }
    for(int i=0; i<numCourses; i++)
        visited[i]=0;

    bool cycle=false;
    for(int i=0; i<numCourses; i++)
    {
        if(visited[i]==0)
        {
            bool get_cycle=cycle_detected(i);
            if(get_cycle)
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<vector<int>>v(a, vector<int>(b));
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
            cin>>v[i][j];
    }
    cout<<canFinish(n,v)<<endl;
}

/**

4
4
2
1 0
2 0
3 1
3 2

*/
