#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& v)
{
    int n = v.size();
    int pref=1, suff=1;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(pref == 0) pref = 1;
        if(suff == 0) suff = 1;
        pref *= v[i];
        suff *= v[n-i-1];
        ans = max(ans, max(pref, suff));
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProduct(v)<<endl;
}
/**

4
-1 2 -1 -1

*/
