#include<bits/stdc++.h>
using namespace std;

int dp[15][10005];
int coinChange(vector<int>&v, int t)
{
    int n=v.size();
    for(int i=1;i<=n;i++)
        dp[i][0]=0;
    for(int j=0;j<=t;j++)
        dp[0][j]=INT_MAX-1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(j>=v[i-1]){
                dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][t]==INT_MAX-1) return -1;
    return dp[n][t];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int amount;
    cin>>amount;
    cout<<coinChange(v,amount)<<endl;
}
