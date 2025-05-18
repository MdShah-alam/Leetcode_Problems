#include<bits/stdc++.h>
using namespace std;

static const int INF = 1e9;
int ans(int n,int t,vector<int>&v,vector<vector<int>>&dp)
{
    if(t==0) return 0;
    if(n==0) return INF;
    if(dp[n][t]!=-1) return dp[n][t];
    if(v[n-1]<=t)
        dp[n][t] = min(1+ans(n,t-v[n-1],v,dp),ans(n-1,t,v,dp));
    else dp[n][t] = ans(n-1,t,v,dp);
    return dp[n][t];
}
int coinChange(vector<int>&v, int t)
{
    int n = v.size();
    vector<vector<int>>dp(n+1,vector<int>(t+1 ,-1));
    int res = ans(n,t,v,dp);
    if(res>=INF) return -1;
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int amount;
    cin>>amount;
    cout<<coinChange(v,amount)<<endl;
    return 0;
}
