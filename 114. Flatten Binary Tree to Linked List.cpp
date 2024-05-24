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

void print(TreeNode *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

vector<int> store(TreeNode *root , vector<int>&v)
{
    if(root==NULL) return v;
    v.push_back(root->val);
    store(root->left,v);
    store(root->right,v);

    return v;
}

void flatten(TreeNode* root)
{
    vector<int>v;
    v = store(root,v);
    cout<<v.size()<<endl;
    TreeNode *rot=new TreeNode(v[0]);
    queue<TreeNode*>q;
    q.push(rot);
    int i=1;
    for(int i=1;i<v.size();i++){
        TreeNode *node=q.front();
        q.pop();
        TreeNode *newNode=new TreeNode(v[i]);
        node->right=newNode;
        q.push(newNode);
    }
    print(rot);
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root = new TreeNode(n);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        TreeNode *n1=NULL;
        TreeNode *n2=NULL;
        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        node->left=n1;
        node->right=n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl;
    flatten(root);
    cout<<endl;
    return 0;
}/**

1
2 5
3 4 -1 6
-1 -1 -1 -1 -1 -1

*/
