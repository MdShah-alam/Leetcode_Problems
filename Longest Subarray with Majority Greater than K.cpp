#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>&v, int k)
{
    int n=v.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        v[i]=v[i]>k?1:-1;
    }
    unordered_map<int,int>first_occurrence;
    int prefix_sum=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        prefix_sum+=v[i];

        if(prefix_sum>0)
            max_len=i+1;
        else{
            if(first_occurrence.find(prefix_sum-1)!=first_occurrence.end()){
                max_len = max(max_len,i-first_occurrence[prefix_sum-1]);
            }
        }

         if(first_occurrence.find(prefix_sum)==first_occurrence.end())
            first_occurrence[prefix_sum]=i;
    }
    return max_len;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k;
    cin>>k;
    cout<<longestSubarray(v,k)<<endl;
    return 0;
}
/**

5
1 2 3 4 5
3

*/
