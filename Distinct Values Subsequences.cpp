#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    unordered_map<int,int>mp;

    for(int i=0;i<n;i++)
        mp[v[i]]++;

    long long ans = 1;
    sort(v.begin(),v.end());

    for(auto & [val,f] : mp ){
        ans = (ans*(f+1)+MOD)%MOD;
    }
    ans = (ans-1+MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}
