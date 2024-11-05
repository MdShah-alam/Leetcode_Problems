#include<bits/stdc++.h>
using namespace std;

int coinChangeMemo(vector<int>& coins, int amount, vector<int>& memo) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    if (memo[amount] != -2) return memo[amount];

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeMemo(coins, amount - coin, memo);
        if (res >= 0 && res < minCoins) {
            minCoins = res + 1;
        }
    }

    memo[amount] = (minCoins == INT_MAX ? -1 : minCoins);
    return memo[amount];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -2);
    return coinChangeMemo(coins, amount, memo);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int amount;
    cin>>amount;
    cout<<coinChange(v,amount)<<endl;
    return 0;
}
