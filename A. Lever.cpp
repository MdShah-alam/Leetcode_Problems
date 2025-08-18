#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    while(n--){
        int m;
        cin>>m;
        vector<int>a(m);
        for(int i=0;i<m;i++)
            cin>>a[i];
        int ans=0,temp;
        for(int i=0;i<m;i++){
            cin>>temp;
            ans+=max(0,a[i]-temp);
        }
        ans++;
        v.push_back(ans);
    }

    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
