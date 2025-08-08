#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& v)
{
    int zeros=0;
    bool found = false;
    int p = 1;
    int n = v.size();
    for(int i=0;i<n;i++){
        if(v[i]!=0)
            p*=v[i];
        else{
            found = true;
            zeros++;
        }
    }
    vector<int>result(n);
    if(found){
        for(int i=0;i<n;i++){
            if(zeros>1)
                result[i]=0;
            else{
                if(v[i]==0)
                    result[i]=p;
                else
                    result[i]=0;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            result[i]=p/v[i];
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>ans = productExceptSelf(v);
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;
}
