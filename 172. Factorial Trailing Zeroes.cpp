#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n)
{
    int zeros=0;
    int i=5;
    while(i<=n){
        zeros+=n/i;
        i=i*5;
    }
    return zeros;
}

int main()
{
    int n;
    cin>>n;

    cout<<trailingZeroes(n)<<endl;

    return 0;
}
