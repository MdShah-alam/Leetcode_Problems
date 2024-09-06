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

void print(TreeNode* root)
{
    if(root==NULL)
        return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

vector<int> largestValues(TreeNode* root)
{
    vector<int>v;

    queue<TreeNode*>q;
    q.push(root);
    int value=root->val;
    q.push(NULL);
    while(!q.empty()){
        TreeNode* present=q.front();
        q.pop();
        if(present!=NULL){
            if(value<present->val)
                value=present->val;
            if(present->left!=NULL)
                q.push(present->left);
            if(present->right!=NULL)
                q.push(present->right);
        }
        else{
            v.push_back(value);
            value=INT_MIN;
            if(!q.empty())
                q.push(NULL);
        }
    }
    return v;
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

    print(root);
    cout<<endl;

    vector<int>v=largestValues(root);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

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


