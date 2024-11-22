#include<bits/stdc++.h>
using namespace std;

vector<int>findOrder(int n, vector<vector<int>>&v)
{
    vector<int>inDegree(n,0);
    vector<int>adj_list[n];
    for(auto x : v){
        adj_list[x[1]].push_back(x[0]);
        inDegree[x[0]]++;
    }
    for(int i=0;i<inDegree.size();i++)
        cout<<inDegree[i]<<" ";
    cout<<endl;

    queue<int>q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0)
            q.push(i);
    }

    vector<int>ans;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(int neighbor : adj_list[curr]){
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if(ans.size()==n) return ans;
    return {};
}

int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    vector<vector<int>>v(a, vector<int>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)
            cin>>v[i][j];
    }

    vector<int>k=findOrder(n,v);
    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
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
