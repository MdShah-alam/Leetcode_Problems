#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int>&v)
{
    int n = v.size();
    vector<int>k(n+1,0);
    for(int x : v){
        if(x>=n)
            k[n]++;
        else
            k[x]++;
    }
    int h = n;
    int papers = k[n];
    while(papers<h){
        h-=1;
        papers+=k[h];
    }
    return h;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<hIndex(v)<<endl;
    return 0;
}
/**

5
3 0 6 1 5

*/
