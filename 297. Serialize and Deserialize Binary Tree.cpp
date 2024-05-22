#include<bits/stdc++.h>
using namespace std;
vector<int>v;

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

 string serialize(TreeNode* root)
 {
     if(!root) return "";
     string s = "";
     queue<TreeNode*>q;
     q.push(root);

     while(!q.empty()){
        TreeNode* currnode=q.front();
        q.pop();
        if(currnode==NULL) s.append("#,");

        else s.append(to_string(currnode->val)+",");
        if(currnode!=NULL){
            q.push(currnode->left);
            q.push(currnode->right);
        }
     }
     return s;
 }

 TreeNode* deserialize(string data)
 {
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode *root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        getline(s,str,',');

        if(str == "#")
            node->left=NULL;
        else{
            TreeNode *leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#")
            node->right=NULL;
        else{
            TreeNode *rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
 }

void print(TreeNode* root)
{
    if(root==NULL) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
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
        TreeNode* n2=NULL;

        if(x!=-1) n1=new TreeNode(x);
        if(y!=-1) n2=new TreeNode(y);

        node->left=n1;
        node->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    print(root);
    cout<<endl;
    string s = serialize(root);
    cout<<s<<endl;

    TreeNode* newroot = deserialize(s);
    print(newroot);
    cout<<endl;

    return 0;
}

/**

1
2 3
4 -1 -1 5
-1 -1 -1 -1

1
2 3
4 -1 -1 -1
-1 9
-1 -1

12 3  4 9

*/

