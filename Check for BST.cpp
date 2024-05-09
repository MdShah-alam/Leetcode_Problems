#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* constructTree(vector<int>&v , int l , int r)
{
    if(l>r)
        return NULL;
    int mid = l +(r-l)/2;
    TreeNode * root = new TreeNode(v[mid]);

    root->left = constructTree(v , l , mid-1);
    root->right = constructTree(v, mid+1 , r);
    return root;
}

bool isValidBST(TreeNode* root , long minval , long maxval)
{
    if(root==NULL) return true;

    if(root->val >= maxval || root->val <= minval) return false;
    return isValidBST(root->left , minval , root->val)&&isValidBST(root->right, root->val , maxval);
}

bool isBST(TreeNode* root)
{
    return isValidBST(root , numeric_limits<int>::min() , numeric_limits<int>::max());
}

void print(TreeNode* root)
{
    if(root==NULL)
        return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    TreeNode *root = constructTree(v,0,n-1);

    cout<<endl;
    print(root);
    cout<<endl;
    cout<<isBST(root);
    return 0;
}
/**

5
1 2 3 4 5

*/

