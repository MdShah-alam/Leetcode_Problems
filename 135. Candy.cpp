#include<bits/stdc++.h>
using namespace std;

int candy(vector<int>&v)
{
    int n = v.size();
    if(n==1) return 1;
    if(n==2){
        if(v[0]<v[1] || v[1]<v[0]) return 3;
        else return 2;
    }
    vector<int>k(n,1);
    if(v[0]>v[1]) k[0]=2;

    for(int i=1;i<n;i++){
        if(v[i-1]<v[i])
            k[i]=k[i-1]+1;
    }

    for(int i=0;i<n;i++)
        cout<<k[i]<<" ";
    cout<<endl;

    if(v[n-1]>v[n-2]) k[n-1] = k[n-2]+1;

    for(int i=n-1;i>0;i--){
        if(v[i-1]>v[i] && k[i-1]<=k[i])
            k[i-1] = k[i]+1;
    }

    for(int i=0;i<n;i++)
        cout<<k[i]<<" ";
    cout<<endl;

    int ans=0;

    for(int i=0;i<n;i++)
        ans+=k[i];

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
/**

5
1 0 2 1 0

*/
