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

TreeNode *check(vector<int>&pre,int preStart,int preEnd, vector<int>&in,int inStart,int inEnd,unordered_map<int,int>&mp)
{
    if(preStart>preEnd || inStart>inEnd) return nullptr;
    int x = pre[preStart];
    TreeNode *root = new TreeNode(x);
    int inRoot = mp[x];
    int numsLeft = inRoot - inStart;
    root->left = check(pre,preStart+1, preStart+numsLeft, in, inStart, inRoot-1,mp);
    root->right = check(pre, preStart+1+numsLeft, preEnd,in,inRoot+1,inEnd, mp);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.size()==0) return nullptr;
    unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    return check(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
}

void print(TreeNode *root)
{
    if(!root) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}
int main()
{
    int n;
    cin>>n;
    vector<int>in(n),pre(n);
    for(int i=0;i<n;i++)
        cin>>in[i];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    TreeNode *root = buildTree(pre , in);
    print(root);
    return 0;
}
/**

5
9 3 15 20 7
3 9 20 15 7


*/
