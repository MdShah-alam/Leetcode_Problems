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
        next=NULL;
    }
};

Node * insert_at_tail(Node *&head , int val)
{
    Node *newnode = new Node(val);

    if(head==NULL){
        head=newnode;
        return head;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

Node * delete_nth_node(Node *&head , int n)
{
    Node * dummy = new Node(0);
    dummy->next=head;
    Node * left=dummy;
    Node * right=head;

    while(n>0 && right!=NULL){
        right=right->next;
        n--;
    }
    while(right!=NULL){
        left=left->next;
        right=right->next;
    }
    left->next=left->next->next;
    return dummy->next;
}

void printList(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head=insert_at_tail(head,a);
    }

    printList(head);
    cout<<endl;

    int a;
    cin>>a;

    Node * head1=delete_nth_node(head,a);
    printList(head1);
    return 0;
}
