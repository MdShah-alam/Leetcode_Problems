#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<int>>&ans,vector<int>&demo,vector<int>v,int t,int idx)
{
    if(t==0){
        ans.push_back(demo);
        return;
    }
    if(t<0 && idx>=v.size()) return ;
    for(int i=idx;i<v.size();i++){
        if(t>=v[i]){
            demo.push_back(v[i]);
            help(ans,demo,v,t-v[i],i);
            demo.pop_back();
        }
    }
}
vector<vector<int>>combinationSum(vector<int>&v, int t)
{
    vector<vector<int>>ans;
    vector<int>demo;
    sort(v.begin(),v.end());
    help(ans,demo,v,t,0);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    vector<vector<int>>ans = combinationSum(v,target);
    for(vector<int>k : ans){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}

/**

4
2 3 6 7
7

*/
