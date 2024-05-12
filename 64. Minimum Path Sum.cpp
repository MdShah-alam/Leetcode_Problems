#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int d=INT_MAX;
    int n=grid.size();
    int m=grid[0].size();

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=d;
    }

    dp[n][m-1]=0;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid;

    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        grid.push_back(v);
    }

    cout<<minPathSum(grid)<<endl;
    return 0;
}
/**

2 3
1 2 3
4 5 6

3 3
1 3 1
1 5 1
4 2 1

*/
