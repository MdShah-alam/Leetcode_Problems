#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int n=nums.size();
    int left=0,minLength=INT_MAX;
    int sum=0;

    for(int right=0;right<n;right++){
        sum+=nums[right];
        while(sum>=target){
            minLength = min(minLength , right-left+1);
            sum-=nums[left];
            left++;
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
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
    cout<<minSubArrayLen(target , v)<<endl;

    return 0;
}
