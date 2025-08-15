#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>&v)
{
    int total = 0;
    int maxsum=v[0], curMax=0;
    int minsum=v[0], curMin=0;
    for(int x : v){
        curMax=max(curMax+x , x);
        maxsum=max(maxsum,curMax);
        curMin = min(curMin+x, x);
        minsum = min(minsum, curMin);
        total+=x;
    }
    if(maxsum<0) return maxsum;
    return max(maxsum,total-minsum);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxSubarraySumCircular(v)<<endl;
    return 0;
}
/**

4
1 -2 3 -2

*/
