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
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void print(Node *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q)
{
    if(!root || root==p || root==q)
        return root;
    Node *left = lowestCommonAncestor(root->left, p,q);
    Node *right = lowestCommonAncestor(root->right,p,q);

    if(!left)
        return right;
    else if(!right)
        return left;
    else
        return root;
}

int main()
{
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=nullptr, *n2=nullptr;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;

    int x, y;
    cin>>x>>y;
    Node *p = new Node(x);
    Node *a = new Node(y);

    Node *Ancestor = lowestCommonAncestor(root, p,a);
    cout<<Ancestor->val<<endl;
    return 0;
}
/**

5
3 7
1 4 6 8
-1 -1 -1 -1 -1 -1 -1 -1

*/



