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
        this->next = NULL;
    }
};

ListNode* swapPairs(ListNode* head)
{
    if(!head || !head->next) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;

    while(prev->next && prev->next->next){
        ListNode *first = prev->next;
        ListNode *second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }
    return dummy->next;
}

ListNode *insert_at_tail(ListNode *head, int x)
{
    ListNode *newNode = new ListNode(x);

    if(!head) return newNode;

    ListNode *temp = head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void print(ListNode *head)
{
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    ListNode *head = NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        head = insert_at_tail(head, x);
    }

    print(head);
    head = swapPairs(head);
    print(head);

    return 0;
}
