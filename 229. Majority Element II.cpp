#include<bits/stdc++.h>
using namespace std;

vector<int>majorityElement(vector<int>&v)
{
    int n=v.size();
    int can1=0,can2=0,cont1=0,cont2=0;
    for(int x : v){
        if(x==can1) cont1++;
        else if(x==can2) cont2++;
        else if(cont1==0){
            can1=x;
            cont1=1;
        }
        else if(cont2==0){
            can2=x;
            cont2=1;
        }
        else{
            cont1--;
            cont2--;
        }
    }
    cont1=0,cont2=0;
    for(int x : v){
        if(x==can1) cont1++;
        else if(x==can2) cont2++;
    }
    vector<int>result;
    if(cont1 > n/3) result.push_back(can1);
    if(cont2 > n/3) result.push_back(can2);
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>result=majorityElement(v);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
