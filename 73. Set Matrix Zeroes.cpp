#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>&matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>>vv;
    vv=matrix;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                for(int a=0;a<n;a++)
                    vv[a][j]=0;
                for(int b=0;b<m;b++)
                    vv[i][b]=0;
            }
        }
    }
    matrix=vv;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vv(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>vv[i][j];
    }

    setZeroes(vv);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<vv[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
