#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target)
{
    int l=0,h=nums.size()-1;

    while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[l]<=nums[mid]){
            if(target>=nums[l] && target<nums[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        else{
            if(target>nums[mid] && target<=nums[h])
                l=mid+1;
            else
                h=mid-1;
        }
    }
    return -1;
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
    int t;
    cin>>t;
    cout<<search(v,t)<<endl;
    return 0;
}

/**

7
6 7 0 1 2 4 5
0

**/
