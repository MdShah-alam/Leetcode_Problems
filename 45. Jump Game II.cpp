#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int fasther=0;
    int currposition=0;
    int jumps=0;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        fasther = max(fasther,i+nums[i]);
        if(i==currposition){
            currposition=fasther;
            jumps++;
        }
    }
    return jumps;
}
//  3 2 1 0 4
//  2 3 1 1 4
//  2 3 0 1 4
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<jump(v)<<endl;
    return 0;
}

