#include<bits/stdc++.h>
using namespace std;

vector<int>v;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void in_order(TreeNode* root){
    if(root==NULL)
        return;
    in_order(root->left);
    v.push_back(root->val);
    in_order(root->right);
}

int kthSmallest(TreeNode* root, int k)
{
    in_order(root);
    return v[k-1];
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

    int k;
    cin>>k;
    cout<<kthSmallest(root,k);

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
3

3
1 4
-1 2 -1 -1
-1 -1

2

*/
