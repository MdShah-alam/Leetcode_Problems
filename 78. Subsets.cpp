#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>subsets;

void generat(vector<int>&subset,int i, vector<int>&nums)
{
    if(i==nums.size()){
        subsets.push_back(subset);
        return ;
    }

    generat(subset,i+1,nums);

    subset.push_back(nums[i]);
    generat(subset,i+1,nums);
    subset.pop_back();
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
    vector<int>a;
    generat(a,0,v);

    for(int i=0;i<subsets.size();i++){
        for(int j=0;j<subsets[i].size();j++)
            cout<<subsets[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
