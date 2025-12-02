#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int st, int mid, int ed)
{
    int i=st;
    vector<int>temp;
    int j=mid+1;
    while(i<=mid && j<=ed){
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=ed){
        temp.push_back(v[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        v[st]=temp[idx];
        st++;
    }
}
void margeSort(vector<int>&v, int l, int r)
{
    if(l<r){
        int mid = l+(r-l)/2;
        margeSort(v,l,mid);
        margeSort(v,mid+1,r);
        merge(v,l,mid,r);
    }
}
void marge(vector<int>&v)
{
    int n = v.size();
    int l=0, r=n-1;
    margeSort(v,l,r);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    marge(v);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}

