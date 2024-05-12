#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums)
{
    int ones = 0;
    int twos = 0;
    for(auto ele:nums){
        ones = (ones^ele) & (~twos);
        twos = (twos^ele) & (~ones);
    }
    return ones;

//    sort(nums.begin() , nums.end());
//
//    if(nums[0]!=nums[1])
//        return nums[0];
//    if(nums[nums.size()-1]!=nums[nums.size()-2])
//        return nums[nums.size()-1];
//
//    for(int i=1;i<nums.size(); i++){
//        if(nums[i-1]!=nums[i])
//            return nums[i-1];
//    }
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
    cout<<singleNumber(v)<<endl;
    return 0;
}
