#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height)
{
    int n = height.size();
    int l=0;
    int r=n-1;
    int a=0;
    while(l<r){
        int b=height[l];
        int c=height[r];
        int d=r-l;
        int e=min(b,c);
        int f=e*d;
        a=max(a,f);
        if(e==b)
            l++;
        else
            r--;
    }
    return a;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<maxArea(v)<<endl;
    return 0;
}
