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
ListNode* reverseKGroup(ListNode* head, int k)
{
    if(!head || k==1) return head;
    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy , *curr = &dummy, *next = &dummy;
    int cont = 0;
    curr = head;

    while(curr){
        cont++;
        curr = curr->next;
    }

    while(cont >= k){
        curr = prev->next;
        next = curr->next;
        for(int i=1;i<k;i++){
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        cont -= k;
    }
    return dummy.next;
}

ListNode *insert_at_tail(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val);
    if(!head) return newNode;
    ListNode *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    ListNode *head = NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head, a);
    }
    print(head);
    int k;
    cin>>k;
    ListNode *head1 = reverseKGroup(head, k);
    print(head1);

    return 0;
}
