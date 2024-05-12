#include<bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k)
{
    sort(happiness.rbegin() , happiness.rend());
    long long total=0;
    for(int i=0;i<k;i++){
        long long currH = happiness[i];
        if(currH-i>=0) total+=currH - i;
    }
    return total;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<"Enter the k's value : ";
    int k;
    cin>>k;
    cout<<maximumHappinessSum(v,k)<<endl;
}
