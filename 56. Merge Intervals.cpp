#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin() , intervals.end());
    vector<vector<int>>result;

    for(auto v : intervals){
        if(result.empty() || result.back()[1] < v[0])
            result.push_back(v);
        else
            result.back()[1] = max(result.back()[1] , v[1]);
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++){
        vector<int>v(2);
        for(int j=0;j<2;j++)
            cin>>v[j];
        vv.push_back(v);
    }

    vector<vector<int>>result=merge(vv);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<2;j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
