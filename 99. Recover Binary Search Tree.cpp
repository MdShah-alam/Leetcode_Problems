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
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode *first;
TreeNode *prev;
TreeNode *middle;
TreeNode *last;

void inorder(TreeNode *root)
{
    if(root==NULL) return ;
    inorder(root->left);

    if(prev!=NULL && (root->val<prev->val)){
        if(first == NULL){
            first = prev;
            middle = root;
        }
        else{
            last=root;
        }
    }

    prev=root;
    inorder(root->right);
}

void recoverTree(TreeNode* root)
{
    first=middle=last=NULL;
    prev = new TreeNode(INT_MIN);

    inorder(root);
    if(first && last) swap(first->val , last->val);
    else swap(first->val,middle->val);
}

void print(TreeNode *root)
{
    if(root==NULL) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root=new TreeNode(n);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode* n1=NULL;
        TreeNode *n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        node->left=n1;
        node->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl;
    print(root);
    cout<<endl;

    recoverTree(root);
    cout<<endl;
    print(root);
    cout<<endl;

    return 0;
}
/**

1
2 3
-1 4 5 -1
-1 6 -1 -1
-1 -1

3
1 4
-1 -1 2 -1
-1 -1

*/

