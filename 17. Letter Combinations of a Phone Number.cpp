#include<bits/stdc++.h>
using namespace std;

vector<string>res;
void helper(int i,string s,unordered_map<char,string>mp,string &curr)
{
    if(i==s.size()){
        res.push_back(curr);
        return ;
    }
    char ch = s[i];
    for(char l : mp[ch]){
        curr+=l;
        helper(i+1,s,mp,curr);
        curr.pop_back();
    }
}
//digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
vector<string> letterCombinations(string s)
{
    if(s=="") return res;
    unordered_map<char,string>mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    string curr="";
    helper(0,s,mp,curr);
    return res;
}

int main()
{
    string s;
    cin>>s;
    vector<string>ans = letterCombinations(s);
    for(string sk : ans)
        cout<<sk<<" ";
    cout<<endl;
    return 0;
}
