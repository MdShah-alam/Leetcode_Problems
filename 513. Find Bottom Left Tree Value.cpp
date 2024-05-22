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

int findBottomLeftValue(TreeNode* root)
{
    if(root==NULL) return 0;

    queue<TreeNode*>q;
    q.push(root);
    int k=0;

    while(!q.empty()){
        int n=q.size();
        vector<int>v;

        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            v.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        k=v[0];
    }
    return k;
}

void print(TreeNode* root)
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
        TreeNode* n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        node->left=n1;
        node->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    print(root);
    cout<<endl;

    cout<<findBottomLeftValue(root)<<endl;

    return 0;

}/**

1
2 3
4 -1 -1 5
-1 -1 -1 6
-1 -1

1
2 3
4 -1 -1 -1
-1 9
-1 -1

*/

