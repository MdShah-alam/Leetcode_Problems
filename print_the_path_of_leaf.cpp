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

void getpath(Node* root , vector<string>v , vector<vector<string>>&ar)
{
    if(!root){
        return ;
    }
    bool found=true;

    if(root->left==NULL && root->right==NULL){
        v.push_back(to_string(root->val));
        ar.push_back(v);
        found=false;
    }

    if(found){
        string s=to_string(root->val);
        s = s+"->";
        v.push_back(s);
    }

    getpath(root->left , v, ar);
    getpath(root->right, v , ar);

    v.pop_back();
    return ;
}

vector<vector<string>> solve(Node *root)
{
    vector<vector<string>>ar;
    vector<string>v;
    if(root==NULL)
        return ar;
    getpath(root,v, ar);
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
    cout<<endl;

    vector<vector<string>>v = solve(root);

    for(int j=0 ;j<v.size(); j++){
        for(int i=0;i<v[j].size();i++){
            cout<<v[j][i];
        }
        cout<<endl;
    }
    return 0;
}
/**

1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1

*/
