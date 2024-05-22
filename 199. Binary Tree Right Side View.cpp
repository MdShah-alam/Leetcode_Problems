#include<bits/stdc++.h>
using namespace std;
vector<int>v;

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

vector<int> rightSideView(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    vector<int>v;
    if(root==NULL) return v;

    while(!q.empty()){
        int n=q.size();
        vector<int>helper;

        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            helper.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        v.push_back(helper[helper.size()-1]);
    }
    return v;
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

    vector<int>a=rightSideView(root);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;

}/**

1
2 3
4 -1 -1 5
-1 -1 -1 6
-1 -1

*/
