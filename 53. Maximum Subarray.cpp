#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& v)
{
    int currsum=0;
    int maxsum=0;
    for(int i=0;i<v.size();i++){
        currsum+=v[i];
        if(currsum>maxsum)
            maxsum=currsum;
        if(currsum<0)
            currsum=0;
    }
    return maxsum;
}

int main()
{
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<maxSubArray(ar)<<endl;
}
