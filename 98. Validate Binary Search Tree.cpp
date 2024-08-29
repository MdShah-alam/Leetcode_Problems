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

bool dfs(TreeNode* node , int mn, int mx){
    if(node==NULL)
        return true;
    if(!(node->val<mx) && (node->val>mn))
        return false;
    return (dfs(node->left,mn,node->val)&& dfs(node->right,node->val,mx));
}

bool isValidBST(TreeNode* root)
{
    if(root==NULL) return true;
    int mn = INT_MIN;
    int mx = INT_MAX;

    return dfs(root,mn,mx);
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
    cout<<isValidBST(root)<<endl;
    return 0;
}
/**

1
2 2
3 4 4 3
-1 -1 -1 -1 -1 -1 -1 -1

1
2 3
3 4 4 -1
-1 -1 -1 -1 -1 -1

2
5 3
-1 -1 -1 -1

5
1 4
-1 -1 3 6
-1 -1 -1 -1

*/

