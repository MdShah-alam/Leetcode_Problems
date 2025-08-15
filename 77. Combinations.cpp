#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&res, vector<int>&v, int start, int n, int k)
{
    if(v.size()==k){
        res.push_back(v);
        return ;
    }

    for(int i = start; i<=n;i++){
        v.push_back(i);
        backtrack(res,v,i+1,n,k);
        v.pop_back();
    }
}
vector<vector<int>>combine(int n, int k)
{
    vector<vector<int>>res;
    vector<int>v;
    backtrack(res,v,1,n,k);
    return res ;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>v = combine(n,k);

    for(vector<int>a : v){
        for(int x : a)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
