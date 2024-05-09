#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node * left;
    Node * rigth;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->rigth=NULL;
    }
};

void level_order(Node * root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* parent = q.front();
        q.pop();
        cout<<parent->val<<endl;

        if(parent->left!=NULL) q.push(parent->left);
        if(parent->rigth!=NULL) q.push(parent->rigth);
    }
}

void insert_bst(Node *&root , int val)
{
    if(root==NULL){
        root=new Node(val);
        return ;
    }

    if(val < root->val) insert_bst(root->left , val);
    else insert_bst(root->rigth,val);
}

Node * insert_bst(int l , int r , int ar[])
{
    if(l > r) return NULL;
    int mid = l + (r-l)/2;
    Node * newNode = new Node(ar[mid]);
    newNode->left = insert_bst(l , mid-1, ar);
    newNode->rigth = insert_bst(mid+1 , r , ar);
    return newNode;
}

Node * min_node(Node * root)
{
    if(root == NULL) return NULL;
    Node *x = min_node(root->left);
    if(x==NULL) return root;
    else return x;
}

Node * deleteNode(Node * root , int key)
{
    if(root==NULL) return NULL;
    if(root->val == key){
        if(root->left==NULL && root->rigth==NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node *temp = root->rigth;
            delete root;
            root = temp;
        }
        else if(root->rigth == NULL){
            Node *temp = root->left;
            delete root;
            root = temp;
        }
        else{
            Node *mn = min_node(root->rigth);
            root->val = mn->val;
            root->rigth=deleteNode(root->rigth , mn->val);
        }
    }
    else if(key < root->val)
        root->left = deleteNode(root->left,key);
    else root->rigth = deleteNode(root->rigth,key);
    return root ;
}

int main()
{
    int n;
    cin>>n;
    Node * root=NULL;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    root = insert_bst(0,n-1,ar);
    level_order(root);

    int d;
    cout<<"Enter a value that you want to delete : ";
    cin>>d;

    root = deleteNode(root , d);
    level_order(root);

    return 0;
}
