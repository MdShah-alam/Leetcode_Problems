#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& v)
{
    vector<int>l;
    vector<int>r;
    int n = v.size();
    l.push_back(v[0]);
    int b=v[0];

    for(int i=1;i<n;i++){
        if(b<v[i]){
            b=v[i];
            l.push_back(b);
        }
        else
            l.push_back(b);
    }

    reverse(v.begin(),v.end());
    r.push_back(v[0]);
    b=v[0];

    for(int i=1;i<n;i++){
        if(b<v[i]){
            b=v[i];
            r.push_back(b);
        }
        else
            r.push_back(b);
    }
    reverse(r.begin(),r.end());
    reverse(v.begin(),v.end());

    int result=0;
    for(int i=0;i<n;i++){
        int m=min(l[i],r[i]);
        m=m-v[i];
        result+=m;
    }
    return result;
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

    cout<<trap(v)<<endl;
    return 0;
}
/**
12
0 1 0 2 1 0 1 3 2 1 2 1
*/
