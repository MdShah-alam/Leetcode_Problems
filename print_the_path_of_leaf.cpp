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

void print(Node* root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

bool getpath(Node* root , int b, vector<int>&ar)
{
    if(!root) return false;
    ar.push_back(root->val);

    if(root->val == b){
        return true;
    }
    if(getpath(root->left , b, ar)||getpath(root->right,b,ar))
        return true;

    ar.pop_back();
    return false;
}

vector<int> solve(Node *root,int b)
{
    vector<int>ar;
    if(root==NULL)
        return ar;
    getpath(root,b,ar);
    return ar;
}

int main()
{
    int a;
    cin>>a;
    Node *root=new Node(a);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node * presentNode = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        presentNode->left=n1;
        presentNode->right=n2;
    }

    print(root);

    int k;
    cout<<endl<<"Enter a value: ";
    cin>>k;

    vector<int>v = solve(root,k);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
/**

1
2 3
-1 4 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
