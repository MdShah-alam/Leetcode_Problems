#include<bits/stdc++.h>
using namespace std;

void calculate(vector<int>&v, int n, vector<vector<int>>&ans, vector<int>&d, vector<bool>&used)
{
    if(d.size()==n){
        ans.push_back(d);
        return ;
    }
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        used[i]=true;
        d.push_back(v[i]);
        calculate(v,n,ans,d,used);
        d.pop_back();
        used[i]=false;
    }
}
vector<vector<int>>permute(vector<int>&v)
{
    int n = v.size();
    vector<vector<int>>ans;
    vector<int>demo;
    vector<bool>used(n, false);
    calculate(v,n,ans,demo,used);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<vector<int>>x = permute(v);

    for(vector<int>k : x){
        for(int a : k)
            cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}
