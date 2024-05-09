#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score)
{
    map<int,string>s;
    vector<int>v;
    vector<string>s2;

    v=score;
    sort(score.begin(),score.end());
    reverse(score.begin(),score.end());
    int n = score.size();

    for(int i=0; i<n; i++){
        if(i==0)
            s[score[i]] = "Gold Medal";
        else if(i==1)
            s[score[i]] = "Silver Medal";
        else if(i==2)
            s[score[i]] = "Bronze Medal";
        else
            s[score[i]] = to_string(i+1);
    }
    for(int i=0;i<n;i++){
        s2.push_back(s[v[i]]);
    }
    return s2;
}

int main() {
    int n;
    cin>>n;
    vector<int>v;


    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

    vector<string>s = findRelativeRanks(v);

    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}


