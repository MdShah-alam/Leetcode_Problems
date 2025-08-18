#include<bits/stdc++.h>
using namespace std;


int fun(string &s, string &t, int n, int m, vector<vector<int>> &dp) {
    if (n == 0) return m; // insert all remaining characters of t
    if (m == 0) return n; // delete all remaining characters of s

    if (dp[n][m] != -1) return dp[n][m];

    if (s[n-1] == t[m-1])
        return dp[n][m] = fun(s, t, n-1, m-1, dp); // match, no cost
    else
        return dp[n][m] = 1 + min({fun(s,t,n-1,m,dp),fun(s,t, n ,m-1,dp),fun(s,t,n-1,m-1,dp)});
}

int editDistance(string &s, string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return fun(s, t, n, m, dp);
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t)<<endl;
    return 0;
}
/**

geek gesek

*/
