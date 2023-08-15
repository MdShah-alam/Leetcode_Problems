#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k)
{
    k=k%nums.size();

    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int k;
    cin>>k;
    rotate(nums,k);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
