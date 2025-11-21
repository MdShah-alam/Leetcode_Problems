#include<bits/stdc++.h>
using namespace std;

int help(vector<int>&v, int n, vector<int>&dp)
{
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    if(v[n]>v[n-1])
        return dp[n] = max(help(v, n-1, dp)+1, help(v,n-1, dp));
    else return dp[n] = help(v, n-1, dp);
}
int lengthOfLIS(vector<int>&v)
{
    int n = v.size();
    vector<int>dp(n,-1);
    return help(v,n-1,dp);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<lengthOfLIS(v)<<endl;
    return 0;
}
/**

8
10 9 2 5 3 7 101 18

6
0 1 0 3 2 3

5
1 1 1 1 1

6
4 10 4 3 8 9

*/
