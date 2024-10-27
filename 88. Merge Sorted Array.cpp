#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
    for(int i=0;i<nums1.size();i++)
        cout<<nums1[i]<<" ";
    cout<<endl;
}

int main()
{
    int a,b;
    cin>>a>>b;
    vector<int>v1(a),v2(b);
    for(int i=0;i<a;i++)
        cin>>v1[i];
    for(int j=0;j<b;j++)
        cin>>v2[j];

    int n,m;
    cin>>n>>m;
    merge(v1,n,v2,m);
    return 0;
}
/**

6 3
1 2 3 0 0 0
2 5 6
3 3

*/
