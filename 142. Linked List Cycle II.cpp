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

Node *insert_at_tail(int val, Node *head)
{
    Node *newNode=new Node(val);
    if(head==NULL)
        return head=newNode;
    Node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return head;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
bool cycle(Node *head)
{
    Node *fast=head;
    Node *slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}

void create_cycle(Node *&head)
{
    Node *temp=head;
    Node *second=head->next;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=second;
}
Node *detectCycle(Node *head)
{
    Node *fast=head;
    Node *slow=head;
    bool found=false;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            found=true;
            break;
        }
    }
    if(!found) return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        head=insert_at_tail(val,head);
    }
    print(head);
    cout<<endl;
    create_cycle(head);
    if(cycle(head))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    Node *node = detectCycle(head);
    cout<<node->val<<endl;

    return 0;
}
