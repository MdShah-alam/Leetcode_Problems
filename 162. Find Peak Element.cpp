#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>&v)
{
    int left=0, right=v.size()-1;
    while(left<right){
        int mid = left+(right-left)/2;
        if(v[mid]>v[mid+1])
            right=mid;
        else
            left=mid+1;
    }
    return left;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<findPeakElement(v)<<endl;
    return 0;
}
