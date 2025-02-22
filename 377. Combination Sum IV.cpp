#include<bits/stdc++.h>
using namespace std;

int dp[1005];
int help(vector<int>&v,int t)
{
    if(t==0) return 1;
    if(dp[t]!=-1) return dp[t];

    int a=0;
    for(int x : v){
        if(t>=x)
            a+=help(v,t-x);
    }
    return dp[t]=a;
}
int combinationSum4(vector<int>&v,int target)
{
    for(int i=0;i<=target;i++)
        dp[i]=-1;
    return help(v,target);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target=0;
    cin>>target;
    cout<<combinationSum4(v,target)<<endl;
    return 0;
}
