#include<bits/stdc++.h>
using namespace std;

int partition_part(vector<int>& v, int low , int high)
{
    int pivot = v[low];
    int i=low,j=high;
    while(i<j){
        while(v[i] <= pivot && i<=high-1)
            i++;
        while(v[j] > pivot && j>=low+1)
            j--;
        if(i<j) swap(v[i] , v[j]);
    }
    swap(v[low] , v[j]);
    return j;
}
void quicksort(vector<int>&v,int left, int right)
{
    if(left>=right) return ;
    int pivot = partition_part(v,left,right);
    quicksort(v,left, pivot-1);
    quicksort(v,pivot+1, right);
}
vector<int>sortArray(vector<int>&v)
{
    quicksort(v,0,v.size()-1);
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int>ans=sortArray(v);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

/**

6
5 1 1 2 0 0

*/
