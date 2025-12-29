#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>&v)
{
    int n = v.size();
    int i=0,j=n-1;
    int ans = 0;
    while(i<j){
        ans = max(ans,(j-i)*min(v[j],v[i]));
        if(v[i]>v[j])
            j--;
        else i++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<maxArea(v)<<endl;
    return 0;
}
/**

9
1 8 6 2 5 4 8 3 7

*/
