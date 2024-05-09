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

void print(Node *root)
{
    if(root == NULL)
        return ;
    print(root->left);
    cout<<root->val<<" ";
    print(root->rigth);
}

int sum(Node * root , int sum1)
{
    if(root->left==NULL && root->rigth==NULL)
        sum1=sum1+root->val;
    if(root->left!=NULL)
        sum1=sum(root->left,sum1);
    if(root->rigth!=NULL)
        sum1=sum(root->rigth,sum1);
    return sum1;
}

int leftleave(Node *root , int sum)
{
    if(root->left!=NULL){
        if(root->left->left==NULL && root->left->rigth==NULL)
            sum=sum+root->left->val;
        else
            sum=leftleave(root->left,sum);
    }
    if(root->rigth!=NULL)
        sum = leftleave(root->rigth,sum);
    return sum;
}

int main()
{
    int a;
    cin>>a;
    Node * root=new Node(a);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
    Node * presentRoot = q.front();
    q.pop();
    int x,y;
    cin>>x>>y;
    Node *n1=NULL;
    Node *n2=NULL;
    if(x!=-1) n1=new Node(x);
    if(y!=-1) n2=new Node(y);
    presentRoot->left=n1;
    presentRoot->rigth=n2;

    if(n1!=NULL) q.push(n1);
    if(n2!=NULL) q.push(n2);
    }

    print(root);

    int sum1=0;
    int sun=sum(root,sum1);
    cout<<endl<<sun<<endl;
    int b=0;
    int sum2=leftleave(root,b);
    cout<<sum2<<endl;

    return 0;
}
/**

1
2 3
4 -1 5 6
-1 8 -1 -1 -1 7
-1 -1 -1 -1

*/
