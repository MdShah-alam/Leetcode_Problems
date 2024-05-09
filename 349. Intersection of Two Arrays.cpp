#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int>v;
        for(int i=0;i<nums1.size();i++){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end();
            if (it) {
                auto it1 = find(v.begin(), v.end(), nums1[i]) != v.end();
                if(!it1)
                    v.push_back(nums1[i]);
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

3 5
4 9 5
9 4 9 8 4

 */
