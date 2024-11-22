#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>kSmallestPairs(vector<int>&v1, vector<int>&v2, int k)
{
    vector<vector<int>>v;
    int n=v1.size();
    int i=0,j=0;
    while(i<n && j<n){
        int sum1=v[i]+v[j];
        int sum2=v[i+1]+v[j];
        int sum3=v[i]+v[j+1];
        if(sum1<sum2){

        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v1(n),v2(n);
    for(int i=0;i<n;i++)
        cin>>v1[i];
    for(int i=0;i<n;i+++)
        cin>>v2[i];
    int k;
    cin>>k;
    vector<vector<int>>v=kSmallestPairs(v1,v2,k);
    for(int i=0;v.size();i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }
    return 0;
}
