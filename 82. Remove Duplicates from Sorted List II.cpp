#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val=data;
        this->next=NULL;
    }
};

Node *insert_at_tail(Node *&head , int a)
{
    if(head==NULL) return head = new Node(a);

    Node *temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(a);
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

Node *deleteDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL) return head;
    Node* pseudo=new Node(0);
    pseudo->next=head;
    Node *itr=pseudo;

    while(itr->next && itr->next->next){
        if(itr->next->val == itr->next->next->val){
            int variable = itr->next->val;
            while(itr->next!=NULL && itr->next->val==variable)
                itr->next=itr->next->next;
        }
        else
            itr=itr->next;
    }
    return pseudo->next;
}

int main()
{
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head,a);
    }
    print(head);
    cout<<endl;

    Node *temp = deleteDuplicates(head);
    print(temp);

    return 0;
}/**

7
1 2 3 3 4 4 5

*/

