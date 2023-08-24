#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<int>v;
    int i=0,j=0;
    while(i<n || j<m){
        if(i<n && j<m){
            v.push_back(min(nums1[i],nums2[j]));
            if(nums1[i]<nums2[j])
                i++;
            else
                j++;
        }
        else if(i<n){
            v.push_back(nums1[i]);
            i++;
        }
        else{
            v.push_back(nums2[j]);
            j++;
        }
    }
    if(v.size()==1)
        return (double)v[0];
    else if(v.size()==2){
        int sum = v[0]+v[1];
        return (double)sum / 2;
    }
    else{
        if(v.size()%2!=0)
            return (double)v[v.size()/2];
        else{
            int sum = v[v.size()/2]+v[v.size()/2-1];
            return (double)sum/2;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v1,v2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    cout<<findMedianSortedArrays(v1,v2)<<endl;
    return 0;
}
