#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets(vector<int>&v)
{
    vector<vector<int>>ans;
    ans.push_back({});
    for(int i=0;i<v.size();i++){
        int n = ans.size();
        for(int j=0;j<n;j++){
            vector<int>curr = ans[j];
            curr.push_back(v[i]);
            ans.push_back(curr);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> k = subsets(v);
    for(vector<int>x : k){
        for(int y : x)
            cout<<y<<" ";
        cout<<endl;
    }
}
