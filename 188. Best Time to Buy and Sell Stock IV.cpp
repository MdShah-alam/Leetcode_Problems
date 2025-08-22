#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>&v)
{
    int n=v.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int b=0;b<2;b++){
            for(int c=1;c<k+1;c++){
                if(b)
                    dp[i][b][c]=max(-v[i]+dp[i+1][0][c],dp[i+1][1][c]);
                else
                    dp[i][b][c]=max(v[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
            }
        }
    }
    return dp[0][1][k];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int k;
    cin>>k;
    cout<<maxProfit(k,v)<<endl;
    return 0;
}
/**

6
3 2 6 5 0 3
2

*/
