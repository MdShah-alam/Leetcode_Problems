#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
TreeNode* buildBST(vector<int>&v, int left, int right)
{
    if(left>right) return nullptr;

    int mid = left + (right - left)/2;
    TreeNode *root = new TreeNode(v[mid]);

    root->left = buildBST(v, left, mid-1);
    root->right = buildBST(v, mid+1, right);

    return root;
}
TreeNode* sortedArrayToBST(vector<int>&v)
{
    int n = v.size();
    return buildBST(v, 0, n-1);
}

void print(TreeNode *root)
{
    if(!root) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    TreeNode *root = sortedArrayToBST(v);
    print(root);
    cout<<endl;

    return 0;
}
