#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&res, vector<int>&k, vector<int>&v, vector<bool>&used)
{
    if(v.size() == k.size()){
        res.push_back(k);
        return ;
    }

    for(int i=0;i<v.size();i++){
        if(used[i]) continue;
        used[i]=true;
        k.push_back(v[i]);
        backtrack(res, k,v,used);
        k.pop_back();
        used[i]=false;
    }
}
vector<vector<int>>permute(vector<int>&v)
{
    vector<vector<int>>res;
    vector<int>k;
    vector<bool>used(v.size(),false);
    backtrack(res,k,v,used);
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<vector<int>>res = permute(v);

    for(vector<int>k : res){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
