#include<bits/stdc++.h>
using namespace std;

int findmax(vector<vector<int>>&grid , int i , int j)
{
    int maxa=INT_MIN;

    for(int x=i;x<i+3;x++){
        for(int y=j;y<j+3;y++){
            maxa = max(grid[x][y] , maxa);;
        }

    }
    return maxa;
}

vector<vector<int>> largestLocal(vector<vector<int>>& grid)
{
    int n=grid.size();
    vector<vector<int>> v(n-2,vector<int>(n-2));

    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            v[i][j]=findmax(grid,i,j);
        }
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vv;
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        vv.push_back(v);
    }
    vector<vector<int>>v=largestLocal(vv);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/**

4
9 9 8 1
5 6 2 6
8 2 6 4
6 2 2 2

*/
