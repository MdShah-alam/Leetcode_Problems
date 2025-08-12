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

class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
};

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
}
/**

5
3 7
1 4 6 8
-1 -1 -1 -1 -1 -1 -1 -1

*/


