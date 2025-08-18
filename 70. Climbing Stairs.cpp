#include<bits/stdc++.h>
using namespace std;

int help(int n, vector<int>&v)
{
    if(n<=2) return n;
    if(v[n]!=-1) return v[n];
    return v[n]=help(n-1,v)+help(n-2,v);
}
int climbStairs(int n)
{
    vector<int>v(n+1,-1);
    return help(n,v);
}

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}
