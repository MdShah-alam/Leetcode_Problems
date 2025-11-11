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
        this->left = NULL;
        this->right = NULL;
    }
};

void print(Node *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

bool GetPath(Node *root, Node *node , vector<int>&v)
{
    if(!root) return false;

    v.push_back(root->val);

    if(root->val == node->val) return true;

    if(GetPath(root->left , node, v)||GetPath(root->right, node, v))
        return true;
    v.pop_back();
    return false;
}

vector<int>PathPrint(Node *root)
{
    int x;
    cin>>x;
    Node *newNode = new Node(x);
    vector<int>v;
    if(!GetPath(root, newNode, v)){
        return {};
    }
    return v;
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
        int x, y;
        cin>>x>>y;
        Node *n1 = NULL , *n2 = NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    vector<int>ans = PathPrint(root);

    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}

/**

1
2 3
4 5 -1 -1
-1 -1 6 7
-1 -1 -1 -1
7

*/
