#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text1 , text2 ;
    cin>>text1>>text2;
    int n=text1.size();
    int m=text2.size();

    int matrix[n+1][m+1];
    for(int i=0;i<=n;i++)
        matrix[i][0]=0;
    for(int i=0;i<=m;i++)
        matrix[0][i]=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(text2[j]==text1[i])
                matrix[i+1][j+1]=matrix[i][j]+1;
            else
                matrix[i+1][j+1]=max(matrix[i][j+1] , matrix[i+1][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<matrix[n][m]<<endl;
    return 0;
}
