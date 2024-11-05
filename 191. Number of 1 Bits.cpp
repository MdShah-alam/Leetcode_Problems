#include<bits/stdc++.h>
using namespace std;

int hammingWeight(int n)
{
    int ans=0;
    while(n){
        ans+=n%2;
        n=n/2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<hammingWeight(n)<<endl;
}
