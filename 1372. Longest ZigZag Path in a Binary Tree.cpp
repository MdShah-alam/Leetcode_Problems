#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *insert_BST(Node *root, int val)
{
    Node *newNode = new Node(val);
    if(root==NULL){
        root=newNode;
        return root;
    }
    if(val<root->val)
        root->left=insert_BST(root->left,val);
    else
        root->right=insert_BST(root->right,val);
    return root;
}
int maxi=0;
void rec(Node *root,int dir, int len)
{
    if(root==NULL) return ;
    maxi=max(len, maxi);
    if(dir==0){
        rec(root->left,dir,1);
        rec(root->right,dir^1,len+1);
    }
    else{
        rec(root->left,dir^1,len+1);
        rec(root->right,dir,1);
    }
    return ;
}
int longestZigZag(Node* root)
{
    if(root==NULL || (root->right==NULL && root->left==NULL))
        return 0;
    rec(root->left,0,1);
    rec(root->right,1,1);
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        root = insert_BST(root,a);
    }

    cout<<longestZigZag(root)<<endl;

    return 0;
}
/**

6
15 10 20 8 12 25

*/
