#include<bits/stdc++.h>
using namespace std;

vector<string>ans;
void helper(int idx, string digits, unordered_map<char,string>mp, string cur_str)
{
    if(idx==digits.size()){
        ans.push_back(cur_str);
        return ;
    }
    char ch = digits[idx];
    for(char letter : mp[ch]){
        cur_str+=letter;
        helper(idx+1,digits,mp, cur_str);
        cur_str.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if(digits == "") return ans;

    unordered_map<char,string>mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    string cur_str="";
    helper(0,digits, mp, cur_str);
    return ans;
}

int main()
{
    string s;
    cin>>s;
    vector<string>v = letterCombinations(s);
    for(string s : v)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
