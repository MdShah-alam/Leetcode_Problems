#include<bits/stdc++.h>
using namespace std;

void Find(vector<int>v,int n,vector<vector<int>>&ans, vector<int>&state,vector<bool>&used)
{
    if(state.size()==n){
        ans.push_back(state);
        return ;
    }
    for(int i=0;i<n;i++){
        if(used[i]==true) continue;
        state.push_back(v[i]);
        used[i]=true;
        Find(v,n,ans,state,used);
        state.pop_back();
        used[i]=false;
    }
}
vector<vector<int>>permute(vector<int>&v)
{
    int n = v.size();
    vector<int>demo;
    vector<vector<int>>ans;
    vector<bool>used(n,false);
    Find(v,n,ans,demo, used);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>>result = permute(v);
    for(vector<int>k : result){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
