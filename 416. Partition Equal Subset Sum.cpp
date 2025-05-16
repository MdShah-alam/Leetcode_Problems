#include<bits/stdc++.h>
using namespace std;

bool subset(vector<int>&v, int n, int t,vector<vector<int>>&dp)
{
    if(n==0){
        if(t==0)
            return true;
        return false;
    }
    if(dp[n][t]!=-1) return dp[n][t];
    if(t>=v[n-1]){
        dp[n][t]=subset(v,n-1,t-v[n-1],dp)||subset(v,n-1,t,dp);
    }
    else dp[n][t]=subset(v,n-1,t,dp);
    return dp[n][t];
}

bool canPartition(vector<int>&v)
{
    int sum=0;
    int n = v.size();
    for(int i=0;i<v.size();i++)
        sum+=v[i];
    int t = sum/2;
    if(t*2!=sum) return false;
    vector<vector<int>>dp(n+1,vector<int>(t+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++)
            dp[i][j]=-1;
    }
    return subset(v,n,t,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<canPartition(v)<<endl;
    int sum =0 ;
    for(int i=0;i<n;i++)
        sum+=v[i];
    int t = sum/2;
    int dp[n+1][t+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int j=1;j<=t;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(v[i-1]<=j)
                dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
