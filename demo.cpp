#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

Node *insert_at_tail(Node *head, int val)
{
    Node *newNode  = new Node(val);
    if(!head) return newNode;

    Node *temp = head;
    while(temp->next!=nullptr)
        temp=temp->next;

    temp->next = newNode;
    return head;
}

void reverseSegment(Node *&temp)
{
    Node *c=temp;
    Node *p=nullptr;
    while(c){
        Node *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    temp = p;
}
Node *getKthNode(Node *temp ,int k)
{
    Node *node=temp;
    k-=1;
    while(node && k--)
        node=node->next;
    return node;
}

Node *reverseKGroup(Node *head, int k)
{
    Node *temp=head;
    Node *prevList = nullptr;
    while(temp){
        Node *KthNode = getKthNode(temp, k);
        if(!KthNode){
            if(prevList) prevList->next=temp;
            break;
        }
        Node *nextNode = KthNode->next;
        KthNode->next=nullptr;
        Node *tail = temp;
        reverseSegment(temp);
        if(!prevList)
            head = KthNode;
        else
            prevList->next=KthNode;
        tail->next=nextNode;
        prevList=tail;
        temp=nextNode;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    Node *head = nullptr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head, a);
    }
    print(head);
    head = reverseKGroup(head , 4);
    print(head);

    return 0;
}
/**

10
1 2 3 4 5 6 7 8 9 10

*/
