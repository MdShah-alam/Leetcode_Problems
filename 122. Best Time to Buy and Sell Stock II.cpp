#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&v)
{
    int n = v.size();
    int profit=0;
    for(int i=0;i<n-1;i++){
        if(v[i]<v[i+1])
            profit+=v[i+1]-v[i];
    }
    return profit;
}
//  7 1 5 3 6 4
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProfit(v)<<endl;
    return 0;
}
