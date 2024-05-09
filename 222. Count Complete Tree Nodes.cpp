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

int print(Node * root)
{
    if(root==NULL)return 0;
    int x =print(root->left);
    int y =print(root->right);
    return x+y+1;
}

int main()
{
    int a;
    cin>>a;
    Node * root=new Node(a);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
    Node * presentRoot = q.front();
    q.pop();
    int x,y;
    cin>>x>>y;
    Node *n1=NULL;
    Node *n2=NULL;
    if(x!=-1) n1=new Node(x);
    if(y!=-1) n2=new Node(y);
    presentRoot->left=n1;
    presentRoot->right=n2;

    if(n1!=NULL) q.push(n1);
    if(n2!=NULL) q.push(n2);
    }
    int k=0;
    cout<<print(root)<<endl;

    return 0;
}
