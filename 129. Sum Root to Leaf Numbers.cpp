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
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void print(TreeNode *root)
{
    if(!root) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int sumNumbers(TreeNode* root, int sum=0)
{
    if(!root) return 0;
    if(!root->left && !root->right)
        return sum+root->val;
    int result=0;
    result+=sumNumbers(root->left, (sum+root->val)*10)+sumNumbers(root->right, (sum+root->val)*10);
    return result;
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
        TreeNode *n1 = nullptr, *n2 = nullptr;
        if(x!=-1) n1 = new TreeNode(x);
        if(y!=-1) n2 = new TreeNode(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    cout<<sumNumbers(root)<<endl;
    return 0;
}
/**

5
2 8
1 4 7 9
-1 -1 2 -1 6 -1 -1 -1
-1 -1 -1 -1

*/

