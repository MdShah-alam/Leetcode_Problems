#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&v)
{
    int n = v.size();
    int ans = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        ans = max(ans,sum);
        if(sum<0)
            sum=0;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxSubArray(v)<<endl;
    return 0;
}
/**

9
-2 1 -3 4 -1 2 1 -5 4

*/
