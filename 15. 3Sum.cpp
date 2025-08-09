#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>threeSum(vector<int>& v)
{
    sort(v.begin(),v.end());
    int n = v.size();
    vector<vector<int>>ans;

    for(int i=0;i<n-2;i++){
        if(i>0 && v[i]==v[i-1]) continue;
        int l=i+1, r=n-1;
        while(l<r){
            int total = v[i]+v[l]+v[r];
            if(total==0){
                ans.push_back({v[i],v[l],v[r]});
                l++;
                r--;
                while(l<r && v[l]==v[l-1]) l++;
                while(l<r && v[r]==v[r+1]) r--;
            }
            else if(total>0) l++;
            else r--;
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

    vector<vector<int>>ans = threeSum(v);

    for(vector<int>k : ans){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
/**

6
-1 0 1 2 -1 -4

*/
