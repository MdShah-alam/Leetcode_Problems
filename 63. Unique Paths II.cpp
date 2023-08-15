#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    int visited[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            visited[i][j]=0;
    }

    visited[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==1)
                visited[i][j]=0;
            else
                {
                    if(i==0 && j==0)
                        visited[i][j]=1;
                    else if(i-1<0)
                        visited[i][j]=visited[i][j-1];
                    else if(j-1<0)
                        visited[i][j]=visited[i-1][j];
                    else
                        visited[i][j]=visited[i-1][j]+visited[i][j-1];
                }
        }
    }
    return visited[m-1][n-1];
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>v;
    for(int i=0;i<m;i++){
        vector<int>vv;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            vv.push_back(a);
        }
        v.push_back(vv);
    }
    cout<<uniquePathsWithObstacles(v)<<endl;
    return 0;
}
