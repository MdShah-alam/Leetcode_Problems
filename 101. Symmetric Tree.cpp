#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

bool dfs(TreeNode *l , TreeNode * r)
{
    if(l==NULL && r==NULL) return true;
    if((l==NULL && r!=NULL) ||(l!=NULL && r==NULL)) return false;
    return ((l->val==r->val)&&dfs(l->left,r->right) &&dfs(l->right,r->left));
}

bool isSymmetric(TreeNode* root)
{
    if(root==NULL) return true;

    return dfs(root->left,root->right);
}

int main()
{
    TreeNode *root=NULL;
    int val ;
    cin>>val;
    root = new TreeNode(val);
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        TreeNode *n1=NULL,*n2=NULL;
        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        present->left=n1;
        present->right=n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<isSymmetric(root)<<endl;
    return 0;
}
/**

1
2 2
3 4 4 3
-1 -1 -1 -1 -1 -1 -1 -1

1
2 2
3 4 4 -1
-1 -1 -1 -1 -1 -1

*/
