#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int st , int mid, int ed)
{
    vector<int>temp;
    int i = st;
    int j = mid+1;
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
    for(int index = 0; index<temp.size();index++)
        v[index+st] = temp[index];
}

void mergeSort(vector<int>&v, int s, int e)
{
    if(s<e){
        int m = s + (e-s)/2;
        mergeSort(v, s, m);
        mergeSort(v, m+1, e);
        merge(v, s,m, e);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    mergeSort(v,0,n-1);
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
