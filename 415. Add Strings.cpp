#include<bits/stdc++.h>
using namespace std;

string addStrings(string a, string b)
{
    long long s=0,k=0;
    for(long long i=0;i<a.size();i++){
        s=s*10+(int(a[i])-48);
    }
    for(long long i=0;i<b.size();i++){
        k=k*10+(int(b[i])-48);
    }
    long long c=s+k;
    if(c==0)
        return to_string(0);
    string ss;
    while(c!=0){
        long long r=c%10;
        c=c/10;
        ss+=to_string(r);
    }
    reverse(ss.begin(),ss.end());
    return ss;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<addStrings(s1,s2)<<endl;
    return 0;
}
