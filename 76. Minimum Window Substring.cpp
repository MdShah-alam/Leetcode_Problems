#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    string ans="";
    int n=s.size(),m=t.size();
    if(n<m) return ans;
    unordered_map<char,int>mp;
    for(int i=0;i<m;i++)
        mp[t[i]]++;
    unordered_map<char,int>demo=mp;
    int i=0,j=0,cont=0,start=0,len=INT_MAX;
    while(j<n){
        if(mp[s[j]]>0)cont++;
        mp[s[j]]--;
        while(cont==m){
            if(len>(j-i+1)){
                len=j-i+1;
                start=i;
            }
            char ch = s[i];
            mp[ch]++;
            if(demo.find(ch)!=demo.end() && demo[ch]==mp[ch])
                cont--;
            i++;
        }
        j++;
    }
    return s.substr(start, len);
}

//      ADOBECODEBANC
//         ABC
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<minWindow(s,t)<<endl;
    return 0;
}
