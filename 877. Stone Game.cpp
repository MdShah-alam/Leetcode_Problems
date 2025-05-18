#include<bits/stdc++.h>
using namespace std;

 bool stoneGameII(vector<int>&v)
 {
     int a=0,b=0;
     int i=0,j=v.size()-1;
     while(i<j){
        if(v[i]>v[j]){
            a+=v[i];
            b+=v[j];
        }
        else{
            a+=v[j];
            b+=v[i];
        }
        i++;
        j--;
     }
     return a>b;
 }

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<stoneGame(v)<<endl;
    return 0;
}
