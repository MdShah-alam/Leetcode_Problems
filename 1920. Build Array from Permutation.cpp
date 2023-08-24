#include<bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums)
{
    int n=nums.size();
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(nums[nums[i]]);
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
    vector<int>vv=buildArray(v);
    for(int i=0;i<vv.size();i++)
        cout<<vv[i]<<" ";
    cout<<endl;
    return 0;
}
