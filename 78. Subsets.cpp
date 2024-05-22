#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& v)
{
    sort(v.begin(),v.end());
    vector<vector<int>>vv;
    int n=v.size();
    for(int i=0;i<(1<<n);i++){
        vector<int>k;
        for(int j=0;j<n;j++){
            if((1<<j)&i)
                k.push_back(v[j]);
        }
        if (find(vv.begin(), vv.end(), k) == vv.end() )
            vv.push_back(k);
    }

    return vv;
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
    vector<vector<int>> vv = subsets(v);

    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
