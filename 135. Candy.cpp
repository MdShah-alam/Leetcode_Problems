#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>&v)
{
    int n = v.size();
    vector<int>can(n,1);
    if(n<=1) return n;
    if(v[0]>v[1]) can[0]=can[1]+1;
    for(int i=1;i<n;i++){
        if(v[i-1]<v[i])
            can[i] = can[i-1]+1;
    }
    vector<int>can2(n,1);
    if(v[n-1]>v[n-2]) can2[n-1]=2;
    for(int j=n-2;j>=0;j--){
        if(v[j]>v[j+1]) can2[j] = can2[j+1]+1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += max(can[i],can2[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<candy(v)<<endl;
    return 0;
}
