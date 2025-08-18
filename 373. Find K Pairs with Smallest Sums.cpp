#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>kSmallestPairs(vector<int>&a, vector<int>&b, int k)
{
    int n = a.size();
    vector<vector<int>>v;
    int i=0,j=0;
    while(k--){
        if(i==0 && j==0)
            v.push_back({a[i],b[j]});
        if(a[i]==b[j]){
            if(i<n-1 && j<n-1 && a[i+1]>b[j+1])
                j++;
            else

        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int k;
    cin>>k;

    vector<vector<int>> ans = kSmallestPairs(a,b,k);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    return 0;
}
