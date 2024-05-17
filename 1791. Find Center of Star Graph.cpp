#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& edges)
{
    int n=edges.size();
    map<int,int>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++)
            m[edges[i][j]]++;
    }

    for(int i=0;i<=10^5;i++){
        if(m[i]==n)
            return i;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vv;

    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<2;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        vv.push_back(v);
    }

    cout<<findCenter(vv)<<endl;
    return 0;
}
