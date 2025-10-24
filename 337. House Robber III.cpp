#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void print(TreeNode *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

pair<int,int>dfs(TreeNode *root)
{
    if(!root) return {0,0};
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int rob_this = root->val + left.second + right.second;

    int skip_this = max(left.first , left.second)+max(right.first, right.second);

    return {rob_this, skip_this};
}
int rob(TreeNode *root)
{
    auto res = dfs(root);
    return max(res.first, res.second);
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root = new TreeNode(n);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *present = q.front();
        q.pop();
        int x, y;
        cin>>x>>y;
        TreeNode *n1 = NULL , *n2 = NULL;
        if(x!=-1) n1 = new TreeNode(x);
        if(y!=-1) n2 = new TreeNode(y);
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        present->left = n1;
        present->right = n2;
    }

    print(root);
    cout<<endl;
    cout<<rob(root)<<endl;

    return 0;
}
/**

3
4 5
1 3 -1 1
-1 -1 -1 -1 -1 -1


3
20 5
100 -1 -1 1
-1 -1 -1 -1

*/
