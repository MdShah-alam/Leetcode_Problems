#include<bits/stdc++.h>
using namespace std;

int dp[40];
int help(int n)
{
    if(n==0) return 0;
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=help(n-1)+help(n-2)+help(n-3);
    return dp[n];
}
int tribonacci(int n)
{
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    return help(n);
}

int main()
{
    int n;
    cin>>n;
    cout<<tribonacci(n)<<endl;
    return 0;
}
