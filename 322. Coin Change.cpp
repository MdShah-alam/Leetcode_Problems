//#include<bits/stdc++.h>
//using namespace std;
//
//int dp[15][10005];
//int solve(int n , vector<int>&v,int target)
//{
//    if(target==0) return dp[n][target];
//    if(n<0){
//        if(target==0) return dp[n][target];
//        return -1;
//    }
//    if(dp[n][target]!=-1) return dp[n][target];
//
//    if(v[n]<=target)
//        dp[n][target]=1+solve(n,v,target-v[n]);
//    dp[n][target]=solve(n-1,v,target);
//    return dp[n][target];
//}
//int coinChange(vector<int>&v, int target)
//{
//    int n=v.size()+1;
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=target;j++)
//            dp[i][j]=-1;
//    }
//    sort(v.begin(),v.end());
//
//    return solve(n-1,v,target);
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    vector<int>v(n);
//    for(int i=0;i<n;i++)
//        cin>>v[i];
//
//    int target;
//    cin>>target;
//    cout<<coinChange(v,target)<<endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a memoization table and initialize with -1 (uncomputed).
        vector<int> dp(amount + 1, -1);
        dp[0] = 0; // Base case: 0 coins are needed to make 0 amount.

        // Recursively find the answer
        return coinChangeRecursive(coins, amount, dp);
    }

    int coinChangeRecursive(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0) return -1; // Invalid case.
        if (dp[amount] != -1) return dp[amount]; // Return the result if it's already computed.

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = coinChangeRecursive(coins, amount - coin, dp);
            cout<<res<<endl;
            if (res != -1) {
                minCoins = min(minCoins, res + 1);
            }
        }

        dp[amount] = (minCoins == INT_MAX) ? -1 : minCoins;
        return dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = solution.coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}

