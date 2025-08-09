#include<bits/stdc++.h>
using namespace std;

// abcabcbb
int lengthOfLongestSubstring(string s)
{
    int n = s.size(),l=0,r=0;
    int maxlen = 0;
    unordered_map<char,int>mp;

    while(r<n){
        char ch = s[r];
        if(mp.find(ch)!=mp.end() && mp[ch]>l)
            l=mp[ch]+1;
        mp[ch]=r;
        maxlen = max(maxlen, r-l+1);
        r++;
    }
    return maxlen;
}

int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
