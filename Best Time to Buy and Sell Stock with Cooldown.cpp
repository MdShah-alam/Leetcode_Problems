#include<bits/stdc++.h>
using namespace std;

int f(int ind,int buy,vector<int>&v,vector<vector<int>>&dp)
{
    if(ind>=v.size()) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==1)
        return dp[ind][buy] = max(-v[ind]+f(ind+1,0,v,dp),f(ind+1,1,v,dp));
    else return dp[ind][buy] = max(v[ind]+f(ind+1,1,v,dp),f(ind+1,0,v,dp));
}

int maxProfit(vector<int>&v)
{
    int n = v.size();
    vector<vector<int>>dp;
    for(int i=0;i<=n;i++)
        dp.push_back({-1 , -1});
    return f(0,1,v,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProfit(v)<<endl;
}
/**

5
1 2 3 0 4

*/
