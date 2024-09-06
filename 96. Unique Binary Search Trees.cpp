#include<bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    long long cadel[n+1];
    cadel[0]=1;
    cadel[1]=1;

    for(int i=2;i<=n;i++){
        cadel[i]=0;
        for(int j=0;j<i;j++){
            cadel[i]+=cadel[j]*cadel[i-j-1];
        }
    }
    return cadel[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<numTrees(n)<<endl;
    return 0;
}
