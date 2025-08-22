#include<bits/stdc++.h>
using namespace std;

int helper(string s,string t, int n, int m, vector<vector<int>>&dp)
{
    if(n==0) return m;
    if(m==0) return n;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==t[m-1])
        return dp[n][m]=helper(s,t,n-1,m-1,dp);
    else
        return dp[n][m] = min({helper(s,t,n-1,m,dp),helper(s,t,n,m-1,dp),helper(s,t,n-1,m-1,dp)})+1;
}
int minDistance(string s,string t)
{
    int m=s.size(),n=t.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return helper(s,t,m,n,dp);
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minDistance(s,t)<<endl;
    return 0;
}
/**

horse ros

*/
