#include<bits/stdc++.h>
using namespace std;

vector<int>spiralOrder(vector<vector<int>>&matrix)
{
    vector<int> result;
    if (matrix.empty()) return result;

    int m = matrix.size();       // Number of rows
    int n = matrix[0].size();    // Number of columns

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for(int i=left;i<=right;i++)
            result.push_back(matrix[top][i]);
        top++;

        // Traverse down along the right column
        for(int i=top;i<=bottom;i++){
            result.push_back(matrix[i][right]);
        }
        right--;

        // Traverse from right to left along the bottom row (if still within bounds)
        if (top <= bottom) {
            for(int i=right;i>=left;i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse up along the left column (if still within bounds)
        if (left <= right) {
            for(int i=bottom;i>=top;i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vv(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vv[i][j];
        }
    }

    vector<int>v=spiralOrder(vv);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}
