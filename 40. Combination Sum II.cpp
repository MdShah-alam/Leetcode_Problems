#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind,int t,vector<int>&v,vector<vector<int>>&ans,vector<int>&ds)
{
    if(t==0){
        ans.push_back(ds);
        return ;
    }
    for(int i=ind;i<v.size();i++){
        if(i>ind && v[i]==v[i-1]) continue;
        if(v[i]>t)break;
        ds.push_back(v[i]);
        findCombination(i+1,t-v[i],v,ans,ds);
        ds.pop_back();
    }
}

vector<vector<int>>combinationSum2(vector<int>& v, int t)
{
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    vector<int>ds;
    findCombination(0,t,v,ans,ds);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int t;
    cin>>t;

    vector<vector<int>>vv=combinationSum2(v,t);

    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
