#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums)
{
    int maxR = 0;
    for(int i=0;i<nums.size();i++){
        if(i>maxR) return false;
        maxR=max(maxR, i+nums[i]);
    }
    return true;
}

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
/**

5
2 3 1 1 4

5
3 2 1 0 4

*/
