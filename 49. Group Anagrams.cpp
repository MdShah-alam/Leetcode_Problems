#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string , vector<string>>mp;

    for(string str : strs){
        string key = str;
        sort(key.begin(),key.end());

        if(mp.find(key) == mp.end())
            mp[key] = vector<string>();
        mp[key].push_back(str);
    }

    vector<vector<string>>ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string>str;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        str.push_back(s);
    }
    vector<vector<string>>v=groupAnagrams(str);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
