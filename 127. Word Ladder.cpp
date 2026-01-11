#include<bits/stdc++.h>
using namespace std;

int ladderLength(string s, string t, vector<string>& v)
{
    unordered_set<string>st(v.begin(),v.end());
    if(st.find(t)==st.end()) return 0;
    queue<string>q;
    q.push(s);
    unordered_set<string>visited;
    visited.insert(s);
    int level = 1;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            string word = q.front();
            q.pop();
            if(word==t) return level;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                for(char c='a';c<='z';c++){
                    if(c==ch) continue;
                    word[i]=c;
                    if(st.count(word)&&!visited.count(word)){
                        visited.insert(word);
                        q.push(word);
                    }
                }
                word[i]=ch;
            }
        }
        level++;
    }
    return 0;
}

int main()
{
    string s,t;
    cin>>s>>t;
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<ladderLength(s,t,v)<<endl;
    return 0;
}
/**

hit cog
6
hot dot dog lot log cog

*/
