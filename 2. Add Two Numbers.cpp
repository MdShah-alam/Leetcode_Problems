#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node * next;

    Node (int val)
    {
        this->val = val;
        next = NULL;
    }
};

Node * insert_at_tail(int val , Node *&head)
{
    Node * newnode = new Node(val);
    if(head == NULL)
        return head = newnode;
    Node *temp = head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next = newnode;
    return head;
}

void printList(Node * head)
{
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void create_list(Node * head1 , Node * head2)
{
    Node *temp1,*temp2;
    temp1=head1;
    temp2=head2;
    int n=0,m=0;
    while(temp1!=NULL){
        temp1=temp1->next;
        n++;
    }
    while(temp2!=NULL){
        temp2=temp2->next;
        m++;
    }
    Node *head=NULL;
    int a=0,b=0,c=0;
    while(n!=0 && m!=0){
        c = head1->val+head2->val + b;
        head1 = head1->next;
        head2 = head2->next;
        a = c%10;
        b = c/10;
        head = insert_at_tail(a , head);
        m--;
        n--;
    }
    if(n!=0){
        while(n!=0){
            c = head1->val + b;
            head1=head1->next;
            a = c%10;
            b= c/10;
            head = insert_at_tail(a,head);
            n--;
        }
    }
    if(m!=0){
        while(m!=0){
            c = head2->val + b;
            head2 = head2->next;
            a = c % 10;
            b = c / 10;
            head = insert_at_tail(a , head);
            m--;
        }
    }
    if(b!=0)
        head = insert_at_tail(b, head);
    printList(head);
}

int main()
{
    int n,m;
    cout<<"Enter size of n : ";
    cin>>n;
    cout<<"Enter size of m : ";
    cin>>m;

    Node *head1=NULL;
    cout<<"Enter first list : ";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head1 = insert_at_tail(a,head1);
    }
   // printList(head1);
    cout<<"Enter second list : ";
    Node *head2=NULL;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        head2 = insert_at_tail(a,head2);
    }
    //printList(head2);
    cout<<"Add list is : ";
    create_list(head1,head2);

}
