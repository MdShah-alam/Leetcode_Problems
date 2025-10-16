#include<bits/stdc++.h>
using namespace std;

vector<int>dailyTemperatures(vector<int>&v)
{
    stack<pair<int,int>>st;
    int n = v.size();
    vector<int>k(n);
    for(int i=v.size()-1;i>=0;i--){
        if(st.empty()){
            k[i]=0;
            st.push({v[i],i});
        }
        else{
            while(!st.empty() && st.top().first<=v[i])
                st.pop();

            if(st.empty())
                k[i]=0;
            else
                k[i]=st.top().second-i;
            st.push({v[i],i});
        }
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>k = dailyTemperatures(v);
    for(int i=0;i<k.size();i++)
        cout<<k[i]<<" ";
    cout<<endl;
    return 0;
}
/**

8
73 74 75 71 69 72 76 73

*/
