#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
        this->next=NULL;
    }
};

void print(Node *root)
{
    if(root==NULL) return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
}

Node *connect(Node *root)
{
    if(root==NULL) return root;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        if(size==0)
            return root;

        while(size>0){
            Node *temp=NULL;

            if(size>1){
                temp=q.front();
                q.pop();
                Node *nextAdd = q.front();
                temp->next=nextAdd;
            }
            else{
                temp=q.front();
                q.pop();
            }

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            size--;
        }
    }
    return root;
}

void printf(Node *root)
{
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->next;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *root=new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *node = q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1) n1=new Node(x);
        if(y!=-1) n2=new Node(y);

        node->left=n1;
        node->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    cout<<endl<<"inorder traversal : ";
    print(root);

    cout<<endl;

    Node *rot=connect(root);

    printf(root->left->left);
    cout<<endl;

    return 0;
}/**

1
2 3
4 5 -1 7
-1 -1 -1 -1 -1 -1

*/
