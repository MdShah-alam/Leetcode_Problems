#include<bits/stdc++.h>
using namespace std;

unordered_set<string>st;
int m;
int dp[301];
bool solve(int idx,string s)
{
    if(idx>=m) return true;

    if(dp[idx]!=-1) return dp[idx];

    if(st.find(s)!=st.end())
        return dp[idx]=true;

    for(int l=1;l<=m ; l++){
        string temp = s.substr(idx,l);

        if(st.find(temp)!=st.end() && solve(idx+l , s))
            return dp[idx]=true;
    }
    return dp[idx]=false;
}
bool wordBreak(string s,vector<string>&wordDict)
{
    m=s.size();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<wordDict.size();i++)
        st.insert(wordDict[i]);
    return solve(0,s);
}

int main()
{
//    vector<string>dic;
//    string s;
//    cin>>s;
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        string t;
//        cin>>t;
//        dic.push_back(t);
//    }
    string s = "applepenapple";
    vector<string>wordDict = {"apple","pen"};
    cout<<wordBreak(s,wordDict)<<endl;
    return 0;
}
