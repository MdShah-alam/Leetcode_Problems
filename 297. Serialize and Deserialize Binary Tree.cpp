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
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

string serialize(TreeNode* root)
{
    string s = "";
    if(!root) return s;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *currNode = q.front();
        q.pop();
        if(currNode==NULL) s+="#";
        else s+=to_string(currNode->val);
        s+=",";

        if(currNode){
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;
}
TreeNode *deserialize(string data)
{
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#")
            node->left = NULL;
        else{
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#")
            node->right=NULL;
        else{
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void print(TreeNode* root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
    int x;
    cin>>x;
    TreeNode* root = new TreeNode(x);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* present = q.front();
        q.pop();

        int x, y;
        cin>>x>>y;

        TreeNode *n1=NULL , *n2=NULL;

        if(x!=-1) n1 = new TreeNode(x);
        if(y!=-1) n2 = new TreeNode(y);

        if(n1) q.push(n1);
        if(n2) q.push(n2);

        present->left = n1;
        present->right = n2;
    }

    print(root);
    cout<<endl;
    string data = serialize(root);
    cout<<data<<endl;

    TreeNode *root2 = deserialize(data);
    print(root2);
    cout<<endl;

    return 0;
}
/**

1
2 3
-1 4 5 6
-1 -1 -1 -1 -1 -1

*/
