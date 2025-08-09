#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&v)
{
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            swap(v[i][j],v[j][i]);
    }

    for(int i=0;i<n;i++)
        reverse(v[i].begin(),v[i].end());
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    }

    rotate(v);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

/**

3
1 2 3
4 5 6
7 8 9

4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/
