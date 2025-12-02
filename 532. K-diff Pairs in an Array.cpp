#include<bits/stdc++.h>
using namespace std;

int findPairs(vector<int>& v, int k)
{
    if(k<0) return 0;
    map<int,int>mp;
    for(int x : v) mp[x]++;
    int ans = 0;
    if(k==0){
        for(int x : v){
            if(mp[x]>1) ans++;
        }
    }
    else{
        for(auto &p : mp){
            if(mp.count(p.first+k)) ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<findPairs(v,k)<<endl;
    return 0;
}
/**

5
3 1 4 1 5
2

5
1 2 3 4 5
1

5
1 3 1 5 4
0

*/
