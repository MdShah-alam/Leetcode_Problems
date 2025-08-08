#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    istringstream ss(s);
    string word;
    vector<string>v;
    while(ss>>word)
        v.push_back(word);
    return v[v.size()-1].size();
}

int main()
{
    string s = "   fly me   to   the moon  ";
    cout<<lengthOfLastWord(s)<<endl;
    return 0;
}
