#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>&v, int t)
{
    // return lower_bound(v.begin(),v.end(),t)-v.begin();
    int i=0;
    int j=v.size()-1;
    while(i<=j){
        int m = i + (j - i)/2;
        if(v[m]==t) return m;
        else if(v[m]>t) j=m-1;
        else i=m+1;
    }
    return i;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    cout<<searchInsert(v, target)<<endl;
    return 0;
}
