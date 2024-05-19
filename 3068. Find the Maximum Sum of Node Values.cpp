#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
{
    ll total=accumulate(nums.begin(),nums.end(),0ll);
    ll total_diff=0;
    ll diff;
    int positive_count=0;
    ll min_abs_diff = numeric_limits<int>::max();

    for(auto p : nums){
        diff=(p^k)-p;
        if(diff > 0){
            total_diff += diff;
            positive_count++;
        }
        min_abs_diff = min(min_abs_diff , abs(diff));
    }
    if(positive_count%2==1)
        total_diff = total_diff-min_abs_diff;

    return total + total_diff;
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>v;
    vector<vector<int>>edg;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    cout<<"Enter the value of k :";
    int d;
    cin>>d;

    for(int i=0;i<e;i++){
        vector<int>k;
        int a,b;
        cin>>a>>b;
        k.push_back(a);
        k.push_back(b);
        edg.push_back(k);
    }
    cout<<maximumValueSum(v,d,edg)<<endl;
    return 0;
}
