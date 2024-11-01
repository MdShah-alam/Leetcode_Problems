#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode* next;
    int val;

    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};

ListNode *insert_at_tail(ListNode* head,int val)
{
    ListNode* temp=head;
    ListNode* newNode = new ListNode(val);
    if(temp==NULL){
        return temp=newNode;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return head;
}

void print(ListNode*head)
{
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

void reverse_(ListNode*& head)
{
    if(head==NULL)
        return ;
    ListNode* pre=NULL;
    ListNode *curr=head;
    ListNode *nxt;

    while(curr!=NULL){
        nxt=curr->next;
        curr->next=pre;
        pre = curr;
        curr=nxt;
    }
    head = pre;
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (!head || left == right) return head;

    // Dummy node to simplify the handling of the head node.
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // Step 1: Traverse to the node just before the `left` node.
    ListNode* prev = dummy;
    for (int i = 1; i < left; ++i){
        prev = prev->next;
    }

    // Step 2: Reverse the sublist from `left` to `right`.
    ListNode* curr = prev->next;     // The starting node of the sublist to reverse.
    ListNode* next = nullptr;
    ListNode* sublistPrev = prev;
    cout<<prev->val<<" "<<curr->val<<endl;
    for (int i = 0; i < right - left; ++i){
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        cout<<prev->val<<" "<<curr->val<<" "<<next->val<<endl;
    }

    // Step 3: Clean up and return the modified list.
    head = dummy->next;
    delete dummy;  // Free the dummy node memory.
    return head;
}

int main()
{
    int n;
    cin>>n;
    ListNode* head=NULL;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        head=insert_at_tail(head,a);
    }
    print(head);
    cout<<endl;

    reverse_(head);
    print(head);
    cout<<endl;
    reverse_(head);

    int l,r;
    cin>>l>>r;

    head = reverseBetween(head,l,r);
    print(head);
    cout<<endl;

    return 0;
}
