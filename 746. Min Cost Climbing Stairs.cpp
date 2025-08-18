#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&v,int n, vector<int>&dp)
{
    if(n>=v.size()) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = min(help(v,n+1,dp)+v[n],help(v,n+2,dp)+v[n]);
}
int minCostClimbingStairs(vector<int>&v)
{
    int n = v.size();
    vector<int>dp(n+1,-1);
    int ans1 = help(v,0,dp);
    int ans2 = help(v,1,dp);
    return min(ans1,ans2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<minCostClimbingStairs(v)<<endl;
    return 0;
}
/**

10
1 100 1 1 1 100 1 1 100 1

*/
