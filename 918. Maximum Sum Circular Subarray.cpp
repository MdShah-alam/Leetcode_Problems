#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>&v)
{
    int total=0;
    int maxSum=v[0], curMax=0;
    int minSum=v[0], curMin=0;

    for(int x : v){
        curMax=max(curMax+x, x);
        maxSum=max(maxSum, curMax);

        curMin = min(curMin+x , x);
        minSum = min(minSum , curMin);
        total+=x;
    }
    if(maxSum<0) return maxSum;
    return max(maxSum, total-minSum);
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
