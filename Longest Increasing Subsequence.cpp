#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& arr) {
    vector<int>lis;
    for(int x : arr){
        auto it = lower_bound(lis.begin(),lis.end(),x);
        if(it==lis.end())
            lis.push_back(x);
        else
            *it=x;
    }
    int ans=0;
    for(int x : lis){
        ans+=x;
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
    cout<<LIS(v)<<endl;
    return 0;
}

/**

8
10 22 9 33 21 50 41 60

*/
