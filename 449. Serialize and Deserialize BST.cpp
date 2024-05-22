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
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

string serialize(TreeNode* root)
{
    if(root==NULL) return "";
    string s="";
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();

        if(node==NULL) s+="#,";
        else{
            s+=to_string(int(node->val))+",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data)
{
    if(data=="") return NULL;

    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();

        getline(s,str,',');

        if(str=="#")
            node->left=NULL;
        else{
            TreeNode *leftnode = new TreeNode(stoi(str));
            node->left=leftnode;
            q.push(leftnode);
        }
        getline(s,str,',');
        if(str=="#")
            node->right=NULL;
        else{
            TreeNode *rightnode = new TreeNode(stoi(str));
            node->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root=new TreeNode(n);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode* n1=NULL;
        TreeNode *n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        node->left=n1;
        node->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl;
    print(root);
    cout<<endl;

    string s = serialize(root);
    cout<<s<<endl;

    TreeNode * Root=deserialize(s);
    print(Root);

    return 0;
}
/**

1
2 3
-1 4 5 -1
-1 6 -1 -1
-1 -1

*/
