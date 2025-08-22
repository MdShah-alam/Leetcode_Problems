#include<bits/stdc++.h>
using namespace std;

int ans=0;
int helper(int n, int m,vector<vector<char>>& v, vector<vector<int>>&dp)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    int down = helper(n-1,m,v,dp);
    int right = helper(n,m-1,v,dp);
    int diag = helper(n-1,m-1,v,dp);

    dp[n][m]=0;
    if(v[n-1][m-1]=='1')
        dp[n][m]=1+min({down,right,diag});
    ans = max(ans, dp[n][m]);
    return dp[n][m];
}
int maximalSquare(vector<vector<char>>& v)
{
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    helper(n,m,v,dp);
    return ans*ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    cout<<maximalSquare(v)<<endl;
    return 0;
}
/**

5 4
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

*/
