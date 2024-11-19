#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& v)
{
    vector<vector<int>>result;
    sort(intervals.begin(), intervals.end());
    sort(v.begin(), v.end());
    int i=0, n=intervals.size();

    while(i<n && intervals[i][1]<v[0]){
        result.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=v[1]){
        v[0]=min(intervals[i][0],v[0]);
        v[1]=max(intervals[i][1],v[1]);
        i++;
    }
    result.push_back(v);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
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

    vector<int>v(2);
    for(int i=0;i<2;i++)
        cin>>v[i];

    vector<vector<int>>result=insert(vv,v);
    for(int i=0;i<result.size();i++){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    return 0;
}
