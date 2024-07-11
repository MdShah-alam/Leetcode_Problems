#include<bits/stdc++.h>
using namespace std;

int dp[205][20005];
int subset(int n,int t,vector<int>&v)
{
    if(n==-1){
        if(t==0)
            return 1;
        else
            return 0;
    }
    if(t==0)
        return 1;
    if(dp[n][t]!=-1)
        return dp[n][t];

    int ans1=subset(n-1,t,v);
    if(t<v[n]){
        dp[n][t]=ans1;
        return ans1;
    }
    int ans2=subset(n-1,t-v[n] , v);
    dp[n][t]=ans1 || ans2;
    return dp[n][t];
}

bool canPartition(vector<int>&v)
{
    int n=v.size();
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=v[i];
    if(ans%2!=0)
        return false;
    int target=ans/2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++)
            dp[i][j]=-1;
    }

    return subset(n-1,target,v);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<canPartition(v)<<endl;
    return 0;
}
