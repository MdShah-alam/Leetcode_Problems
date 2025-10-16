#include<bits/stdc++.h>
using namespace std;

vector<int>maxSlidingWindow(vector<int>&v, int k)
{
    vector<int>a;
    int n = v.size();
    deque<int>d;
    for(int i=0;i<n;i++){
        if(!d.empty() && d.size()==i-k)
            d.pop_front();
        while(!d.empty() && v[d.back()]<v[i])
            d.pop_back();
        d.push_back(i);
        if(i>=k-1)
            a.push_back(v[d.front()]);
    }
    return a;
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
    vector<int>k=maxSlidingWindow(v,a);

    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;

    return 0;
}
/**

8
1 3 -1 -3 5 3 6 7
3

*/
