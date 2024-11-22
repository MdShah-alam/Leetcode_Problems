#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

Node *insert_at_tail(Node *root, int val)
{
    Node *newNode = new Node(val);
    if(root==NULL)
        return root=newNode;
    Node *temp=root;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return root;
}

Node *mergeTwoLists(Node *head1 , Node *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;

    Node *head=NULL;
    Node *temp=0;
    Node *temp1=head1;
    Node *temp2=head2;
    if(head2->val<head1->val){
        head=head2;
        temp2=temp2->next;
    }
    else{
        head = head1;
        temp1 = temp1->next;
    }
    temp=head;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<temp2->val){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    if(temp1){
        while(temp1){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
    }
    if(temp2){
        while(temp2){
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
    }
    return head;
}

void print(Node *root)
{
    if(root==NULL)
        return ;
    Node *temp=root;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Node *root1=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        root1=insert_at_tail(root1,a);
    }
    Node *root2=NULL;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        root2=insert_at_tail(root2,a);
    }

    print(root1);
    Node *root = mergeTwoLists(root1,root2);
    print(root);

    return 0;
}

/**

3
1 2 4

*/
