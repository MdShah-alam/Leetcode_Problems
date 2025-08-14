#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    for(vector<int>v: matrix){
        int m = v.size();
        if(v[0]<=target && v[m-1]>=target){
            int i=0,j=m-1;
            while(i<=j){
                int m = i+(j-i)/2;
                if(v[m]==target) return m;
                else if(v[m]<target) i=m+1;
                else j=m-1;
            }
            return -1;
        }
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    int target;
    cin>>target;
    cout<<searchMatrix(v,target)<<endl;
    return 0;
}
