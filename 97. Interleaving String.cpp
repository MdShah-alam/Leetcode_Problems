#include<bits/stdc++.h>
using namespace std;

bool helper(string s, string t,string st,int i, int j, int k, vector<vector<int>>&dp)
{
    if(i==s.size() && j==t.size() && k==st.size())
        return true;

    if(dp[i][j]!=-1) return dp[i][j];

    bool x=false,y=false;

    if(i!=s.size() && s[i]==st[k])
        x=helper(s,t,st,i+1,j,k+1,dp);

    if(j!=t.size() && t[j]==st[k])
        y=helper(s,t,st,i,j+1,k+1,dp);

    return dp[i][j]=x || y;
}
bool isInterleave(string s, string t, string st)
{
    int n=s.size();
    int m=t.size();
    int mn=st.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return helper(s,t,st,0,0,0,dp);
}

int main()
{
    string s,t,st;
    cin>>s>>t>>st;

    cout<<isInterleave(s,t,st)<<endl;
    return 0;
}
/**

aabcc
dbbca
aadbbcbcac

*/
