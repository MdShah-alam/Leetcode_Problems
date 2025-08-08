#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>&v)
{
    int n = v.size();
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    });
    for(int i=0;i<n;i++)
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    return 10;
}

int main()
{
    vector<vector<int>> v = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    cout<<findMinArrowShots(v)<<endl;
    return 0;
}
/**

4
1 2
2 3
3 4
4 5

4
10 16
2 8
1 6
7 12

[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
*/
