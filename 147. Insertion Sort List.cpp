#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *Next;
    Node(int val)
    {
        this->val=val;
        this->Next=NULL;
    }
};
Node* insertionSortList(Node* head)
{
    Node *dummy = new Node(0);
    Node *prev=head,*cur=head->Next;
    dummy->Next = head;
    while(cur){
        if(cur->val>=prev->val){
            prev=cur;
            cur=cur->Next;
            continue;
        }
        Node *temp = dummy;
        while(temp->Next->val<cur->val)
            temp=temp->Next;
        prev->Next=cur->Next;
        cur->Next=temp->Next;
        temp->Next=cur;
        cur=prev->Next;
    }
    return dummy->Next;
}
Node *insert_at_tail(int val,Node *head)
{
    Node *newNode = new Node(val);
    if(head==NULL) return head=newNode;

    Node *temp=head;
    while(temp->Next!=NULL)
        temp=temp->Next;

    temp->Next=newNode;
    return head;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->Next;
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
        head=insert_at_tail(a,head);
    }
    print(head);
    cout<<endl;
    head = insertionSortList(head);
    print(head);
    cout<<endl;
    return 0;
}
