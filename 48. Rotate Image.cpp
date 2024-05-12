#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    vector<vector<int>>vv;
    int n=matrix.size();
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<n;j++)
            v.push_back(matrix[j][i]);
        reverse(v.begin(),v.end());
        vv.push_back(v);
    }

    matrix = vv;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix;
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        matrix.push_back(v);
    }
    rotate(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

/**

3
1 2 3
4 5 6
7 8 9

*/
