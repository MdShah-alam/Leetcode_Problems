#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>v,int i, int buy, int cap, vector<vector<vector<int>>>&dp)
{
    if(cap==0) return 0;
    if(i==v.size()) return 0;
    if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    if(buy)
        return dp[i][buy][cap]=max((-v[i]+helper(v,i+1,0,cap,dp)),helper(v,i+1,1,cap,dp));
    else
        return dp[i][buy][cap]=max((v[i]+helper(v,i+1,1,cap-1,dp)),helper(v,i+1,0,cap,dp));
}
int maxProfit(vector<int>&v)
{
    int n=v.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return helper(v,0,1,2,dp);
}

int maxProfit1(vector<int>&v)
{
    int n=v.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<3;cap++){
                if(buy)
                    dp[i][buy][cap]=max(-v[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                else
                    dp[i][buy][cap]=max(v[i]+dp[i+1][1][cap-1],dp[i][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProfit(v)<<endl;
    cout<<maxProfit1(v)<<endl;
    return 0;
}
/**

8
3 3 5 0 0 3 1 4

*/
