#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>&v)
{
    int n=v.size();
    int l=0,r=n-1,ans=0;
    while(l<r){
        int k = min(v[l],v[r]);
        ans = max(ans, (r-l)*k);
        if(v[l]<v[r])
            l++;
        else
            r--;
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

    cout<<maxArea(v)<<endl;
    return 0;
}
/**

9
1 8 6 2 5 4 8 3 7

*/
