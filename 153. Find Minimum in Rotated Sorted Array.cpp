#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& v)
{
    int l=0,r=v.size()-1;
    int ans = INT_MAX;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[l]<=v[mid]){
            ans = min(v[l],ans);
            l=mid+1;
        }
        else{
            ans = min(ans,v[mid]);
            r=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    cout<<findMin(v)<<endl;
    return 0;
}

