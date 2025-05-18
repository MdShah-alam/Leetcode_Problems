#include<bits/stdc++.h>
using namespace std;

int dfs(int r,int c, int preval,vector<vector<int>>&v,vector<vector<int>>&dp)
{
    if(r<0 || r>=v.size() || c<0 || c>=v[0].size() || v[r][c]<=preval)
        return 0;
    if(dp[r][c]!=-1) return dp[r][c];
    int res =0 ;
    res = max(res,1+dfs(r+1,c,v[r][c],v,dp));
    res = max(res,1+dfs(r-1,c,v[r][c],v,dp));
    res = max(res,1+dfs(r,c+1,v[r][c],v,dp));
    res = max(res,1+dfs(r,c-1,v[r][c],v,dp));
    return dp[r][c]=res;
}

int longestIncreasingPath(vector<vector<int>>&v)
{
    int n=v.size(),m=v[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans,dfs(i,j,-1,v,dp));
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    cout<<longestIncreasingPath(v)<<endl;
    return 0;
}
/**

3 3
9 9 4
6 6 8
2 1 1

*/
