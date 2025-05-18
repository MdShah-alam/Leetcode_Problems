#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>&v)
{
    int n = v.size();
    int m = v[0].size();
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            dp[i][j]=0;
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                if(i==0 && j==0)
                    dp[i][j]=1;
                else if(i-1<0)
                    dp[i][j]=dp[i][j-1];
                else if(j-1<0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
            else dp[i][j]=0;
        }
    }
    return dp[n-1][m-1];
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
    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}
/**

3 3
0 0 0
0 1 0
0 0 0

*/
