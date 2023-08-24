#include<bits/stdc++.h>
using namespace std;

void findcombination(int ind , int target , vector<int>&ar , vector<vector<int>>&ans , vector<int>&v)
{
    if(ind == ar.size()){
        if(target==0)
            ans.push_back(v);
        return ;
    }

    // pick up the element
    if(ar[ind]<=target){
        v.push_back(ar[ind]);
        findcombination(ind+1, target-ar[ind],ar , ans , v);
        v.pop_back();
    }

    findcombination(ind+1 , target , ar , ans , v);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>>ans;
    vector<int>v;
    findcombination(0,target , candidates , ans , v);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int t;
    cin>>t;
    vector<vector<int>>vv = combinationSum2(v,t);

    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
