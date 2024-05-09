#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int>v;
    map<int,int>m;
    for(int i=0;i<nums1.size();i++){
        m[nums1[i]]++;
    }

    for(int i=0;i<nums2.size(); i++){
        auto it = m.find(nums2[i]);
        if(it!=m.end() && it->second>0){
            v.push_back(nums2[i]);
            it->second--;
        }
    }
    return v;
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;
    vector<int>v1;
    vector<int>v2;

    for(int i=0; i<n1; i++)
    {
        int a;
        cin>>a;
        v1.push_back(a);
    }

    for(int i=0; i<n2; i++)
    {
        int a;
        cin>>a;
        v2.push_back(a);
    }

    vector<int>v = intersection(v1,v2);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;
    return 0;
}
/**

4 5
4 9 5 4
9 4 9 8 4

 */
