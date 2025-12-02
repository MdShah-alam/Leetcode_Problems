#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

ListNode *insert_at_tail(int val , ListNode* head)
{
    ListNode* newNode = new ListNode(val);
    if(!head) return newNode;
    ListNode *temp=head;
    while(temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

ListNode *getMid(ListNode *head)
{
    if(!head || !head->next) return head;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev;
}
ListNode *merge(ListNode *l, ListNode *r)
{
    ListNode dummy(0);
    ListNode *temp = &dummy;
    while(l && r){
        if(l->val < r->val){
            temp->next = l;
            temp = temp->next;
            l = l->next;
        }
        else{
            temp->next =r;
            temp = temp->next;
            r = r->next;
        }
    }
    temp->next = l ? l:r;
    return dummy.next;
}
ListNode* sortList(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode *mid = getMid(head);
    if(!mid) return head;
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}

void print(ListNode *head)
{
    while(head){
        cout<<head->val<<" ";
        head=head->next;
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
        head = insert_at_tail(a,head);
    }
    print(head);
    ListNode *had = sortList(head);
    print(had);
}
