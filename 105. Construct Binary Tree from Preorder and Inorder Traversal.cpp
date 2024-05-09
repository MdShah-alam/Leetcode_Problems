#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode * left=NULL;
    TreeNode * right=NULL;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//TreeNode *build(vector<int>&preorder,int preStart , int preEnd, vector<int>& inorder , int inStart , int inEnd , map<int,int>inMap)
//{
//    if(preStart>preEnd || inStart>inEnd) return NULL;
//    TreeNode* root=new TreeNode(preorder[preStart]);
//
//    int inRoot = inMap[root->val];
//    int numsLeft = inRoot - inStart;
//    cout<<numsLeft<<" "<<inRoot<<endl;
//
//    root->left = build(preorder,preStart-1 , preStart+numsLeft , inorder , inStart , inRoot-1 , inMap);
//    root->right = build(preorder , preStart+numsLeft+1 , preEnd , inorder , inRoot+1 , inEnd , inMap);
//
//    return root;
//}

int search_(vector<int>&inorder , int start , int end_ , int curr)
{
    for(int i=start ; i<=end_ ; i++){
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}

TreeNode* Build(vector<int>&preorder,vector<int>&inorder, int start , int end_)
{
    static int idx=0;
    if(start > end_)
        return NULL;

    TreeNode * root = new TreeNode(preorder[idx]);
    idx++;

    int index;
    for(int i= start;i<=end_; i++){
        if(inorder[i]==root->val){
            index=i;
            break;
        }
    }

    root->left = Build(preorder , inorder, start , index-1);
    root->right = Build(preorder, inorder , index+1 , end_);
    return root;
}

TreeNode * buildTree(vector<int>&preorder , vector<int>&inorder)
{
    if(preorder.size() == 1){
        TreeNode* root= new TreeNode(preorder[0]);
        return root;
    }
    TreeNode *root = Build(preorder , inorder , 0 , inorder.size()-1);
    return root;
}

void print(TreeNode * root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    vector<int>preorder;
    vector<int>inorder;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        preorder.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        inorder.push_back(a);
    }

    TreeNode * root=buildTree(preorder,inorder);

    print(root);

    return 0;
}

/**

5
3 9 20 15 7
9 3 15 20 7

*/
