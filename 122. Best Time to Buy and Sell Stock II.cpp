#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&v)
{
    int n = v.size();
    int ans=0;
    int x = v[0],y=0;
    for(int i=1;i<n;i++){
        if(x>v[i] && y==0){
            x=v[i];
        }
        else if(x<v[i] && y<v[i])
            y=v[i];
        else if(x<v[i] && y>v[i]){
            ans = ans + (y-x);
            x=v[i];
            y=0;
            cout<<ans<<" ";
        }
    }
    if(y!=0 && x<y)
        ans+=(y-x);
    cout<<ans<<endl;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<maxProfit(v)<<endl;
    return 0;
}
/**

6
7 1 5 3 6 4

5
2 1 2 0 1

*/
