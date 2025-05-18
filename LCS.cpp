#include<bits/stdc++.h>
using namespace std;

//int ans(int n,int m,string s,string t,vector<vector<int>>&dp)
//{
//    if(n==0 || m==0)
//        return 0;
//    if(dp[n][m]!=-1) return dp[n][m];
//    if(s[n-1]==t[m-1])
//        dp[n][m]=ans(n-1,m-1,s,t,dp)+1;
//    else dp[n][m] = max(ans(n-1,m,s,t,dp),ans(n,m-1,s,t,dp));
//    return dp[n][m];
//}

int LCS(string s,string t)
{
    int n = s.size();
    int m = t.size();
    //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //return ans(n,m,s,t,dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t)<<endl;
    return 0;
}
