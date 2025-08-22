#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>kSmallestPairs(vector<int>&a, vector<int>&b, int k)
{
    int n = a.size();
    vector<vector<int>>ans;
    if(a.size()==0 || b.size()==0 || k==0) return ans;
    using T = tuple<int,int,int>;

    priority_queue<T,vector<T>, greater<T>>pq;

    for(int i=0;i<n && i<k;i++)
        pq.push({a[i]+b[0],i,0});

    while(k-->0 && !pq.empty()){
        auto [sum,i,j] = pq.top();
        pq.pop();
        ans.push_back({a[i],b[j]});
        if(j+1<n)
            pq.push({a[i]+b[j+1],i,j+1});
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<n;j++)
        cin>>b[j];

    int k;
    cin>>k;
    vector<vector<int>> v = kSmallestPairs(a,b,k);

    for(vector<int>s : v)
        cout<<s[0]<<" "<<s[1]<<endl;
    return 0;
}

