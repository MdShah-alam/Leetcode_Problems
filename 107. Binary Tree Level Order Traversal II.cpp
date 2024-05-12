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

void print(TreeNode *root)
{
    if(root==NULL) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>>vv;
    if(root==NULL) return vv;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        vector<int>v;
        int n = q.size();

        for(int i=0;i<n;i++){
            TreeNode* head = q.front();
            q.pop();
            v.push_back(head->val);

            if(head->left!=NULL) q.push(head->left);
            if(head->right!=NULL) q.push(head->right);
        }
        vv.push_back(v);
    }
    reverse(vv.begin() , vv.end());
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
    cout<<endl;
    print(root);
    cout<<endl;
    vector<vector<int>>v = levelOrderBottom(root);

    for(int i=0;i<v.size(); i++){
        for(int j=0; j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
/**

1
2 3
-1 4 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
