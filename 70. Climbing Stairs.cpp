#include<bits/stdc++.h>
using namespace std;

int help(int n, vector<int>&dp)
{
    if(n<=3) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = help(n-1,dp)+help(n-2,dp);
}
int climbStairs(int n)
{
    vector<int>dp(n+1,-1);
    return help(n,dp);
}

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}
