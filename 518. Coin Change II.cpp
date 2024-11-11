#include<bits/stdc++.h>
using namespace std;

int dp[5005][305];
int calculate(int i, int t , vector<int>&v)
{
    if(i==0){
        if(t==0) return 1;
        return 0;
    }

    if(dp[t][i]!=-1)
        return dp[t][i];

    if(t>=v[i-1]){
        dp[t][i] = calculate(i,t-v[i-1],v) + calculate(i-1,t,v);
        return dp[t][i];
    }
    else{
        dp[t][i] = calculate(i-1,t,v);
        return dp[t][i];
    }
}
int change(int t, vector<int>&v)
{
    int n = v.size();
    for(int i=0;i<=t;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    return calculate(n,t,v);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int t;
    cin>>t;
    cout<<change(t,v)<<endl;

    return 0;
}
/**

7
3 5 7 8 9 10 11
500

35502874
*/
