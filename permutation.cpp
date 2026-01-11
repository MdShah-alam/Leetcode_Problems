#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<int>>&ans,vector<int>demo,vector<bool>&used,vector<int>v)
{
    if(demo.size()==v.size()){
        ans.push_back(demo);
        return ;
    }
    for(int i=0;i<v.size();i++){
        if(used[i]) continue;
        demo.push_back(v[i]);
        used[i]=true;
        help(ans,demo,used,v);
        used[i]=false;
        demo.pop_back();
    }
}
vector<vector<int>>permute(vector<int>&v)
{
    vector<vector<int>>ans;
    int n = v.size();
    vector<int>demo;
    vector<bool>used(n);
    help(ans,demo,used,v);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>>ans = permute(v);
    for(vector<int>k:ans){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
