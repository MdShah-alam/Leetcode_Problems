#include<bits/stdc++.h>
using namespace std;

int dp[105];
int val(int i,vector<int>&v)
{
    if(i>=v.size()-1){
        if(i==v.size()-1) return v[i];
        else return 0;
    }
    if(dp[i]!=-1) return dp[i];

    int ans1=v[i]+val(i+2,v);
    int ans2=val(i+1,v);
    dp[i] = max(ans1,ans2);
    return dp[i];
}
int rob(vector<int>&v)
{
    int n=v.size();
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    int ans1 =  val(1,v);

    for(int i=0;i<=n;i++)
        dp[i]=-1;
    v.pop_back();
    int ans2 = val(0,v);
    return max(ans1,ans2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<rob(v)<<endl;
}

