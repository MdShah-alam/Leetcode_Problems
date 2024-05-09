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

void print(Node * root)
{
    if(root==NULL) return ;
    cout<<root->val<<"->";
    print(root->left);
    print(root->right);
}

vector<vector<int>>zigzaglevelOrder(Node * root)
{
    vector<vector<int>>result;
    if(root==NULL)
        return result;

    queue<Node*>q;
    q.push(root);
    bool found=true;

    while(!q.empty()){
        int size_=q.size();
        vector<int>row(size_);
        for(int i=0;i<size_;i++){
            Node *presentNode = q.front();
            q.pop();

            int index=(found)?i:(size_ -1-i);
            row[index]=presentNode->val;
            if(presentNode->left)
                q.push(presentNode->left);
            if(presentNode->right)
                q.push(presentNode->right);
        }
        found = !found;
        result.push_back(row);
    }
    return result;
}

int main()
{
    int a;
    cin>>a;
    Node * root=new Node(a);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *presentNode=q.front();
        q.pop();

        int x , y;
        cin>>x>>y;
        Node *n1=NULL;
        Node *n2=NULL;

        if(x!=-1)n1=new Node(x);
        if(y!=-1)n2=new Node(y);

        presentNode->left=n1;
        presentNode->right=n2;

        if(n1!=NULL)q.push(n1);
        if(n2!=NULL)q.push(n2);
    }

    print(root);
    cout<<endl;
    vector<vector<int>>vv = zigzaglevelOrder(root);
    for(int i=0;i<vv.size();i++){
        vector<int>v=vv[i];
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
}

/**

1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
