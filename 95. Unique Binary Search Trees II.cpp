#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
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

vector<TreeNode*> help(int l,int r)
{
    if(l>r || l<1)
    {
        vector<TreeNode*>v;
        v.push_back(NULL);
        return v;
    }
    if(l==r)
    {
        TreeNode* temp = new TreeNode(l);
        vector<TreeNode*>v;
        v.push_back(temp);
        return v;
    }
    vector<TreeNode*>ans;
    for(int i=l; i<=r; i++)
    {
        vector<TreeNode*>lt=help(l,i-1);
        vector<TreeNode*>rt=help(i+1,r);
        for(int k=0; k<lt.size(); k++)
        {
            for(int j=0; j<rt.size(); j++)
            {
                TreeNode* temp=new TreeNode(i);
                temp->left=lt[k];
                temp->right=rt[j];
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n)
{

}

int main()
{
    int n;
    cin>>n;
    vector<TreeNode*> v = generateTrees(n);
}
