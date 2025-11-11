#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& v, int fee)
{
    int n = v.size();
    vector<int>profit(n),buy(n);
    profit[0]=0;
    buy[0]=v[0];
    for(int i=1;i<n;i++){
        profit[i] = max(profit[i-1],(v[i]-buy[i-1]-fee));
        buy[i] = min(buy[i-1],v[i]-profit[i]);
    }
    return profit[n-1];
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int fee;
    cin>>fee;
    cout<<maxProfit(v,fee)<<endl;
    return 0;
}
/**

6
1 3 2 8 4 9
2

5
1 3 7 10 3
3

*/
