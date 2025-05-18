#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>&v,int n, int t, vector<vector<int>>&dp)
{
    if(n==0) return t==0;
    if(dp[n][t]!=-1) return dp[n][t];
    if(v[n-1]<=t) dp[n][t] = ans(v,n-1,t-v[n-1],dp)+ans(v,n-1,t,dp);
    else dp[n][t]=ans(v,n-1,t,dp);
    return dp[n][t];
}
int findTargetSumWays(vector<int>&v, int target)
{
    int n = v.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    if(target>sum || (target+sum)%2!=0) return 0;
    int t=(target+sum)/2;
    vector<vector<int>>dp(n+1,vector<int>(t+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++)
            dp[i][j]=-1;
    }
    return ans(v,n,t,dp);
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
    cout<<findTargetSumWays(v,target)<<endl;
    return 0;
}

/**

3
1 2 1
0

*/
