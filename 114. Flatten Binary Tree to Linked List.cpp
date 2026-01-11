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
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
        this->next = nullptr;
    }
};

Node* connect(Node* root)
{
    if(!root) return nullptr;
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        while(node!=nullptr){
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            node->next = q.front();
            node = q.front();
            q.pop();
        }
        if(!q.empty())
            q.push(nullptr);
    }
    return root;
}

void print(Node *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
int main()
{
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        int x, y;
        cin>>x>>y;
        Node *n1 = nullptr, *n2 = nullptr;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        node->left = n1;
        node->right = n2;
    }
    print(root);
    cout<<endl;


    return 0;
}
/**

5
2 8
1 3 6 9
-1 -1 -1 -1 -1 -1 -1 -1

*/
