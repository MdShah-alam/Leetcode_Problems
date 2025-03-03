#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& v)
{
    int arr[3];
    for(int i=0;i<3;i++)
        arr[i]=0;
    for(int x : v)
        arr[x]++;
    int j=0;
    for(int i=0;i<3;i++){
        int x=arr[i];
        while(x--){
            v[j]=i;
            j++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sortColors(v);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
