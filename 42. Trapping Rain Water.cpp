#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& v)
{
    int n = v.size();
    vector<int>prefix(n),suffix(n);
    prefix[0]=v[0];
    suffix[n-1]=v[n-1];

    for(int i=1;i<n;i++)
        prefix[i] = max(prefix[i-1],v[i]);
    for(int i=n-2;i>=0;i--)
        suffix[i]=max(suffix[i+1],v[i]);

    int total=0;
    for(int i=0;i<n;i++){
        int left = prefix[i];
        int right = suffix[i];
        if(v[i]<left && v[i]<right)
            total+=min(left,right)-v[i];
    }
    return total;
}

int updateTrap(vector<int>&v)
{
    int n=v.size();
    int l=0,r=n-1,left=0, right=0, total=0;
    while(l<=r){
        if(v[l]>v[r]){
            if(right>v[r])
                total+=(right-v[r]);
            right=max(right,v[r]);
            r--;
        }
        else{
            if(left>v[l])
                total+=(left-v[l]);
            left = max(left, v[l]);
            l++;
        }
    }
    return total;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<trap(v)<<endl;
    cout<<updateTrap(v)<<endl;
    return 0;
}
/**

12
0 1 0 2 1 0 2 3 2 1 2 1

6
4 2 0 3 2 5

*/
