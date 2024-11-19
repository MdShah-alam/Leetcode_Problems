#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *right;
    Node *left;
    Node(int val)
    {
        this->val=val;
        right=NULL;
        left=NULL;
    }
};

void print(Node *root)
{
    if(root==NULL) return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
 void inOrder(Node* node, int &prev, int &minDiff) {
        if (!node) return;
        inOrder(node->left, prev, minDiff);

        if (prev != -1) {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;
        inOrder(node->right, prev, minDiff);
}

int getMinimumDifference(Node *root)
{
    int minDiff=INT_MAX;
    int prev = -1;

    inOrder(root,prev,minDiff);
    return minDiff;
}

int main()
{
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int x,y;
        cin>>x>>y;
        Node *present = q.front();
        q.pop();

        Node *l=NULL;
        Node *r=NULL;
        if(x!=-1) l = new Node(x);
        if(y!=-1) r = new Node(y);

        present->left=l;
        present->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
    }

    print(root);
    cout<<endl<<getMinimumDifference(root)<<endl;

    return 0;
}
/**

4
2 6
1 3 -1 -1
-1 -1 -1 -1

1
0 48
-1 -1 12 49
-1 -1 -1 -1

*/
