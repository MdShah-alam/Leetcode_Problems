#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>&v)
{
    unordered_set<int>numSet;
    for(int x : v)
        numSet.insert(x);
    int longestStreak = 0;
    for(int n : numSet){
        if(numSet.find(n-1)==numSet.end()){
            int currentNum = n;
            int currentStreak = 1;
            while(numSet.find(currentNum+1)!=numSet.end()){
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<longestConsecutive(v)<<endl;
    return 0;
}
