#include<bits/stdc++.h>
using namespace std;

 vector<int> getConcatenation(vector<int>& nums)
 {
    int n=nums.size();
    vector<int>v;
    v = nums;
    for(int i=0;i<nums.size();i++){
        v.push_back(nums[i]);
    }
    return v;
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
    vector<int>ans = getConcatenation(v);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
