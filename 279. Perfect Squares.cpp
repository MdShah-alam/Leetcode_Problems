#include<bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
        dp[i]=n;
    for(int i=1;i<=n;i++){
        for(int s=1;s<=i;s++){
            int square = s*s;
            if(i-square<0) break;
            dp[i]=min(dp[i],1+dp[i-square]);
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
    return 0;
}
