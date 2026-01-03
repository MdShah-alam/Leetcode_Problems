#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& v)
{
    unordered_set<int> st;
    for (int x : v)
        st.insert(x);

    int longest = 0;

    for (int x : st) {
        if (st.find(x - 1) == st.end()) { // start of sequence
            int length = 0;
            while (st.find(x + length) != st.end())
                length++;
            longest = max(longest, length);
        }
    }
    return longest;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<longestConsecutive(v)<<endl;
}
/**

5
3 4 2 1 5

10
0 3 7 2 5 8 4 6 0 1

*/
