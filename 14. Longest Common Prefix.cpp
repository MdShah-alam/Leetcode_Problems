#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string res = "";
    for(int i=0;i<strs[0].size();i++){
        for(string s : strs){
            if(i == s.size() || s[i]!=strs[0][i])
                return res;
        }
        res += strs[0][i];
    }
    return res;
}

int main()
{
    vector<string>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        s.push_back(a);
    }
    cout<<longestCommonPrefix(s)<<endl;
    return 0;
}
