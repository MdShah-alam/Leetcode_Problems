#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if(s.size()<t.size()) return "";

    unordered_map<char, int>have, need;
    for(char ch : t) need[ch]++;

    int haveCount = 0, needCount = need.size();
    int left=0, minLen = INT_MAX, start=0;

    for(int right=0;right<s.size();right++){
        char chs = s[right];
        have[chs]++;

        if(need.count(chs) && have[chs]==need[chs])
            haveCount++;

        while(haveCount == needCount){
            if(right-left+1<minLen){
                minLen = right-left+1;
                start = left;
            }

            char lc = s[left];
            have[lc]--;
            if(need.count(lc) && have[lc] < need[lc])
                haveCount--;
            left++;
        }
    }
    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<minWindow(s,t)<<endl;
    return 0;
}
/**

ADOBECODEBANC
ABC

*/
