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
    queue<TreeNode*>q;
    q.push(root);
    vector<double>v;

    while(!q.empty()){
        int n = q.size();
        double sum=0.00 ;
        for(int i=0;i<n;i++){
            TreeNode* parentNode = q.front();
            q.pop();

            if(parentNode->left){
                q.push(parentNode->left);
            }

            if(parentNode->right){
                q.push(parentNode->right);
            }
            sum = sum + parentNode->val;
        }
        v.push_back(double(sum/n));
    }
}

int main()
{
    int a;
    cin>>a;
    TreeNode* root=new TreeNode(a);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *presentNode=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode * n1=NULL;
        TreeNode * n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        presentNode->left = n1;
        presentNode->right = n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl;
    print(root);
    return 0;
}

/**

1
2 3
-1 4 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
