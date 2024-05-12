#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void getpath(TreeNode* root , vector<int>v , vector<vector<int>>&ar)
{
    if(!root){
        return ;
    }
    v.push_back(root->val);

    if(root->left==NULL && root->right==NULL){
        ar.push_back(v);
    }

    getpath(root->left , v, ar);
    getpath(root->right, v , ar);

    v.pop_back();
    return ;
}

bool hasPathSum(TreeNode *root , int targetSum)
{
    vector<vector<int>>ar;
    vector<int>v;
    if(root==NULL && targetSum==0)
        return true;
    getpath(root,v, ar);

    for(int i=0;i<ar.size() ; i++){
        int sum=0;
        for(int j=0 ;j<ar[i].size() ; j++){
            sum = sum + ar[i][j];
        }
        if(targetSum==sum)
        return true;
    }
    return false;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>>ar,vv;
    vector<int>v;
    if(root==NULL && targetSum==0)
        return vv;
    getpath(root,v, ar);

    for(int i=0;i<ar.size() ; i++){
        int sum=0;
        for(int j=0 ;j<ar[i].size() ; j++){
            sum = sum + ar[i][j];
        }
        if(targetSum==sum)
            vv.push_back(ar[i]);
    }
    return vv;
}

int main()
{
    int a;
    cin>>a;
    TreeNode *root=new TreeNode(a);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *presentNode = q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode* n1=NULL;
        TreeNode* n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        presentNode->left=n1;
        presentNode->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    int targetSum;
    cin>>targetSum;

//    cout<<endl<<hasPathSum(root, targetSum)<<endl;

    vector<vector<int>> v = pathSum(root, targetSum);

    for(int i=0;i<v.size() ; i++){
        for(int j=0; j<v[i].size() ;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/**

1
2 3
7 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1

*/

