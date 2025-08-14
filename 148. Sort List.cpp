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
    if(!head) return newNode;

    ListNode *temp = head;
    while(temp->next)
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

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeTwoLists(ListNode *l1 , ListNode *l2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while(l1 && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }
    if(l1) temp->next = l1;
    else temp->next = l2;
    return dummyNode->next;
}
ListNode* sortList(ListNode* head)
{
    if(!head || !head->next) return head;

    ListNode *middle = findMiddle(head);
    ListNode *righthead = middle->next;
    middle->next = nullptr;
    ListNode *lefthead = head;

    lefthead = sortList(lefthead);
    righthead = sortList(righthead);
    return mergeTwoLists(lefthead , righthead);
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
    head = sortList(head);
    print(head);

    return 0;
}
