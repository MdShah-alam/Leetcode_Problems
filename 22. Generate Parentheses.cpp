#include<bits/stdc++.h>
using namespace std;

void help(int n, int open, int close, string &s, vector<string>&v)
{
    if(open==n && close==n){
        v.push_back(s);
        return ;
    }
    if(open<n){
        s.push_back('(');
        help(n,open+1,close, s,v);
        s.pop_back();
    }
    if(close<open){
        s.push_back(')');
        help(n,open, close+1,s,v);
        s.pop_back();
    }
}
vector<string>generateParenthesis(int n)
{
    string s="";
    vector<string>v;
    help(n,0,0,s,v);
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<string>v = generateParenthesis(n);
    for(string s : v)
        cout<<s<<" ";
    cout<<endl;

    return 0;
}
