#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>&v)
{
    int n = v.size();
    int i=0, j=n-1;
    while(i<j){
        int m = i+(j-i)/2;
        if(v[m]>v[m+1]) j = m;
        else i = m+1;
    }
    return i;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<findPeakElement(v)<<endl;
}
/**

7
1 2 1 3 5 6 4

*/
