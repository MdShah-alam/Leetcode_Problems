#include<bits/stdc++.h>
using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> startMap;
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
        startMap[intervals[i][0]] = i;
    }

    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        int end_i = intervals[i][1];

        auto it = startMap.lower_bound(end_i);

        if (it != startMap.end()) {
            result[i] = it->second;
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>k;
    for(int i=0;i<n;i++){
        vector<int>v(2);
        for(int j=0;j<2;j++)
            cin>>v[j];
        k.push_back(v);
    }
    vector<int>v=findRightInterval(k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/**

3
3 4
2 3
1 2

*/
