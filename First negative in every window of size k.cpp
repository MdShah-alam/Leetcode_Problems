#include<bits/stdc++.h>
using namespace std;

vector<int>firstNegInt(vector<int>& arr, int k)
{
    vector<int>ans;
    deque<int>dp;
    int n = arr.size();

    int i=0,j=0;
    while(j<n){
        if(arr[j]<0)
            dp.push_back(j);

        if(j-i+1<k)
            j++;
        else if(j-i+1 == k){
            if(dp.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[dp.front()]);
            if(!dp.empty() && dp.front() == i)
                dp.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int a;
    cin>>a;
    vector<int>k = firstNegInt(v,a);

    for(int x : k)
        cout<<x<<" ";
    cout<<endl;
}
/**

8
12 -1 -7 8 -15 30 16 28
3

*/
