#include<bits/stdc++.h>
using namespace std;

void helper(vector<string>&v, string &s, int n, int openN, int closeN)
{
    if(openN == closeN && openN == n){
        v.push_back(s);
        return ;
    }
    if(openN < n){
        s.push_back('(');
        helper(v,s,n,openN+1, closeN);
        s.pop_back();
    }

    if(openN>closeN){
        s.push_back(')');
        helper(v,s,n,openN, closeN+1);
        s.pop_back();
    }
}
vector<string>generateParenthesis(int n)
{
    vector<string>v;
    string s="";
    helper(v,s,n,0,0);
    return v;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v = generateParenthesis(n);

    for(string s : v)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
