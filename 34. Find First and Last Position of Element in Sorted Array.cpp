#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>&v, int t)
{
    int i=0,j=v.size();
    while(i<j){
        int m = i+(j-i)/2;
        if(v[m]<t) i=m+1;
        else j=m-1;
    }
    return i;
}
int upperbound(vector<int>&v, int t)
{
    int i=0,j=v.size();
    while(i<j){
        int m = i+(j-i)/2;
        if(v[m]<=t) i=m+1;
        else j=m-1;
    }
    return i;
}
vector<int> searchRange(vector<int>& v, int t)
{
    int left = lowerbound(v,t);
    int right = upperbound(v,t);

    if(left < v.size() && v[left] == t)
        return {left, right};
    return {-1,-1};
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int t;
    cin>>t;
    vector<int>k=searchRange(v,t);

    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
}
