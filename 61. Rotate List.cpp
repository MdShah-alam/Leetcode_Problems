#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *insert_at_tail(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val);
    if(head == nullptr) return newNode;
    ListNode *temp = head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next = newNode;
    return head;
}

void print(ListNode *head)
{
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* rotateRight(ListNode* head, int k)
{
    if(!head || !head->next || k==0) return head;
    int n=1;
    ListNode *tail = head;

    while(tail->next){
        tail = tail->next;
        n++;
    }

    k%=n;
    if(k==0) return head;
    tail->next = head;
    ListNode *new_tail = head;

    for(int i=0;i<n-k-1;i++){
        new_tail = new_tail->next;
    }

    ListNode *new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
}

int main()
{
    int n;
    cin>>n;
    ListNode *head = nullptr;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head, a);
    }
    print(head);

    int k;
    cin>>k;
    head = rotateRight(head, k);
    print(head);

    return 0;
}
