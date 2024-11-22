#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>&wordList)
{
    unordered_set<string>wordset(wordList.begin(),wordList.end());
    if(wordset.find(endWord)==wordset.end())
        return 0;
    queue<pair<string,int>>q;
    q.push({beginWord,1});

    while(!q.empty()){
        auto word = q.front();
        q.pop();
        string curr = word.first;
        int steps = word.second;

        for(int i=0;i<curr.size();i++){
            string tempword = curr;
            for(char ch='a'; ch<='z' ; ch++){
                tempword[i]=ch;
                if(tempword==endWord)
                    return steps+1 ;
                if(wordset.find(tempword)!=wordset.end()){
                    q.push({tempword,steps+1});
                    wordset.erase(tempword);
                }
            }
        }
    }
    return 0;
}

int main()
{
    string start,ends;
    cin>>start>>ends;
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<ladderLength(start,ends,v)<<endl;
    return 0;
}
/**

hit
cog
6
hot dot dog lot log cog

*/

