#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    vector<int>v;
    int a=0, b=0;
    for(int i=digits.size()-1;i>=0;i--){
        if(i == digits.size()-1)
            a = digits[i]+1+b;
        else
            a = digits[i]+b;
        v.push_back(a%10);
        b=a/10;
    }
    if(b>0)
        v.push_back(b);
    reverse(v.begin(),v.end());
    return v;
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
    vector<int>ans = plusOne(v);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
