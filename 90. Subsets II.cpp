#include<bits/stdc++.h>
using namespace std;

void help(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>& ans)
{
    if(i==nums.size())
        ans.push_back(temp);
    else{
        // to take the ith ele
        temp.push_back(nums[i]);
        help(i+1,nums,temp,ans);

        temp.pop_back();

        // to ignore the ith ele
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        help(i+1,nums,temp,ans);
    }
}

vector<vector<int>>subsets(vector<int>&nums)
{
    vector<vector<int>>ans;
    vector<int>temp;
    help(0,nums,temp,ans);
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
    vector<vector<int>>ans=subsets(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
