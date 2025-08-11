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

void print(TreeNode *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

unordered_map<int, int> inorderIndex;

TreeNode *build(int preStart , int preEnd, int inStart, int inEnd , vector<int>&preorder, vector<int>&inorder)
{
    if(preStart>preEnd || inStart>inEnd) return nullptr;

    int rotVal = preorder[preStart];
    TreeNode *root = new TreeNode(rotVal);

    int rootIndexInInorder = inorderIndex[rotVal];
    int leftTreeSize = rootIndexInInorder - inStart;

    root->left = build(preStart+1, preStart+leftTreeSize, inStart, rootIndexInInorder-1, preorder, inorder);
    root->right = build(preStart+leftTreeSize+1, preEnd, rootIndexInInorder+1, inEnd, preorder, inorder);

    return root;
}

TreeNode *buildTree(vector<int>&preorder, vector<int>&inorder)
{
    inorderIndex.clear();
    for(int i=0;i<inorder.size();i++)
        inorderIndex[inorder[i]]=i;

    return build(0,preorder.size()-1,0,inorder.size()-1,preorder, inorder);
}

int main()
{
    int k;
    cin>>k;
    vector<int>preorder(k),inorder(k);

    for(int i=0;i<k;i++)
        cin>>preorder[i];

    for(int i=0;i<k;i++)
        cin>>inorder[i];

    TreeNode *rot = buildTree(preorder, inorder);

    print(rot);
    cout<<endl<<endl;
    return 0;
}

/**

9
5 2 1 4 3 8 7 6 10
1 2 3 4 5 6 7 8 10

*/
