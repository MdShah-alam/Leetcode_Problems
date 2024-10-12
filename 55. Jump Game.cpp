#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int reachable=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>reachable) return false;
        reachable=max(reachable,nums[i]+i);
    }
    return true;
}
//  3 2 1 0 4
//  2 3 1 1 4
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<canJump(v)<<endl;
    return 0;
}
