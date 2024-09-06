#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int maxPath(TreeNode* node,int &maxi)
{
    if(node==NULL) return 0;
    int left=max(0,maxPath(node->left,maxi));
    int right=max(0,maxPath(node->right,maxi));
    maxi=max(maxi,left+right+node->val);
    return max(left,right)+node->val;
}

int maxPathSum(TreeNode* root)
{
    int maxi=INT_MIN;
    maxPath(root,maxi);
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root=new TreeNode(n);

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *present=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode *n1=NULL;
        TreeNode *n2=NULL;

        if(x!=-1)
            n1=new TreeNode(x);
        if(y!=-1)
            n2=new TreeNode(y);

        present->left=n1;
        present->right=n2;

        if(n1!=NULL)
            q.push(n1);
        if(n2!=NULL)
            q.push(n2);
    }

    cout<<maxPathSum(root)<<endl;

    return 0;
}
/**

-4
2 7
3 5 6 9
-1 -1 -1 -1 -1 -1 -1 -1

3
9 20
-1 -1 15 7
-1 -1 -1 -1


*/
