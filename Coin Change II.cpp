#include<bits/stdc++.h>
using namespace std;

int ans(int t,int n ,vector<int>&v,vector<vector<int>>&dp)
{
    if(n==0){
        if(t==0) return 1;
        return 0;
    }
    if(dp[n][t]!=-1) return dp[n][t];
    if(v[n-1]<=t)
        dp[n][t] = ans(t-v[n-1],n,v,dp)+ans(t,n-1,v,dp);
    else
        dp[n][t] = ans(t,n-1,v,dp);
    return dp[n][t];
}

int change(int amount, vector<int>&v)
{
    int n = v.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++)
            dp[i][j]=-1;
    }
    return ans(amount,n,v,dp);
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
    cout<<change(k,v)<<endl;
    return 0;
}

/**

3
1 2 3
4

*/
