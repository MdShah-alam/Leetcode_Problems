#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};

ListNode *insert_at_tail(ListNode *head,int val)
{
    ListNode *newNode=new ListNode(val);
    ListNode *temp=head;
    if(temp==NULL)
        return temp=newNode;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    return head;
}

void print(ListNode *head)
{
    ListNode *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

ListNode* partition(ListNode* head, int x)
{
    ListNode *lessNode=new ListNode(0);
    ListNode *greaterNode=new ListNode(0);

    ListNode *less = lessNode;
    ListNode *greater = greaterNode;

    while(head!=NULL){
        if(head->val<x){
            less->next=head;
            less=less->next;
        }
        else{
            greater->next=head;
            greater=greater->next;
        }
        head=head->next;
    }
    greater->next=NULL;
    less->next=greaterNode->next;

    ListNode *newHead = lessNode->next;
    delete lessNode;
    delete greaterNode;

    return newHead;
}

int main()
{
    int n;
    cin>>n;
    ListNode *head=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head=insert_at_tail(head,a);
    }
    cout<<endl;
    print(head);
    cout<<endl<<endl;

    int x;
    cin>>x;

    head = partition(head,x);
    cout<<endl;
    print(head);
    cout<<endl<<endl;

    return 0;
}
