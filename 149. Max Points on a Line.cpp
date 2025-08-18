#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>&v)
{
    int n = v.size();
    if(n<=2) return n;
    int ans = 2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int total=2;
            for(int k=0;k<n;k++){
                if(k==1 || k==j) continue;
                else if(((v[j][1]-v[i][1])*(v[k][0]-v[i][0]))==((v[k][1]-v[i][1])*(v[j][0]-v[i][0])))
                    total++;
            }
            ans = max(ans,total);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    cout<<maxPoints(v)<<endl;
    return 0;
}

/**

6
1 1 3 2 5 3 4 1 2 3 1 4

*/
