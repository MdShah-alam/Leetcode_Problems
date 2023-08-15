#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m , int n)
{
    int grid[m+1][n+1];
    for(int i=0;i<=m;i++)
        grid[i][n]=0;
    for(int j=0;j<=n;j++)
        grid[m][j]=0;
    grid[m-1][n-1]=1;

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1)
                continue;
            grid[i][j]=grid[i][j+1]+grid[i+1][j];
        }
    }
    return grid[0][0];
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m ,n)<<endl;
    return 0;
}
