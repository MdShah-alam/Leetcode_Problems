#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&res, vector<int>&k,vector<int>&v, int t,int idx)
{
    if(t==0){
        res.push_back(k);
        return ;
    }

    if(t<0 && idx>=v.size()) return ;

    for(int i=idx;i<v.size();i++){
        if(v[i]<=t){
            k.push_back(v[i]);
            helper(res,k,v,t-v[i],i);
            k.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& v, int t)
{
    vector<vector<int>>res;
    vector<int>k;
    helper(res, k,v,t,0);
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    vector<vector<int>>ans = combinationSum(v,k);
    for(vector<int>a : ans){
        for(int x : a)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
