#include<bits/stdc++.h>
using namespace std;

int val(int i,vector<int>&v)
{
    if(i>=v.size()-1){
        if(i==v.size()-1) return v[i];
        else return 0;
    }

    int ans1=v[i]+val(i+2,v);
    int ans2=val(i+1,v);
    return max(ans1,ans2);
}
int rob(vector<int>&v)
{
    return val(0,v);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<rob(v)<<endl;
}
