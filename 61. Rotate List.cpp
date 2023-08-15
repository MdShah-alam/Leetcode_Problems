#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node * next;

    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

Node * insert_at_tail(Node *&head , int val)
{
    Node *newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        return head;
    }

    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

Node * Rotation(Node *&head , int k)
{

    if(head==NULL || head->next==NULL)
        return head;

    Node *newH,*tail;
    newH=head;
    tail=head;
    int l=1;
    while(tail->next!=NULL){
        l++;
        tail=tail->next;
    }

    tail->next=head;
    k=k%l;
    for(int i=0;i<l-k;i++){
        tail=tail->next;
    }
    newH=tail->next;
    tail->next=NULL;
    return newH;
}

void printList(Node * head)
{
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

}

int main()
{
    Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head,a);
    }
    printList(head);
    cout<<endl;

    int k;
    cout<<"Enter the rotation of List : ";

    cin>>k;
    head=Rotation(head,k);
    printList(head);
    cout<<endl;
    return 0;
}
