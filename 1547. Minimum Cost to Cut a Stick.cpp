#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int dfs(int l, int r , vector<int>&v)
{
    if(r-l<=1) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    int res = INT_MAX;
    for(int i=l+1; i<r; i++){
        int cost = v[r]-v[l]+dfs(l,i,v)+dfs(i,r,v);
        res = min(res,cost);
    }
    return dp[l][r]=res;
}
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(),cuts.end());
    int m = cuts.size();
    dp.assign(m,vector<int>(m,-1));

    return dfs(0,m-1,cuts);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(m);
    for(int i=0;i<m;i++)
        cin>>v[i];

    cout<<minCost(n,v)<<endl;
    return 0;
}/**

9 5
5 6 1 4 2

*/
