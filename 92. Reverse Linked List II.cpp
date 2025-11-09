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

ListNode* reverseList(ListNode* head)
{
    ListNode *prev=NULL;
    ListNode *curr=head;
    while(curr){
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

ListNode *reverseLst(ListNode *head,int l, int r)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    int n=l;
    while(curr!=NULL && n<=r){
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        n++;
    }
    head->next=curr;
    return prev;
}
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if(left==right) return head;
    if(left==1){
        ListNode *h = reverseLst(head,left ,right);
        return h;
    }
    else{
        int n=1;
        ListNode *temp=head;
        while(n<left-1){
            temp=temp->next;
            n++;
        }
        temp->next = reverseLst(temp->next,left,right);
        return head;
    }
}

ListNode *insert_at_tail(int x, ListNode *head)
{
    ListNode *newNode = new ListNode(x);
    if(head==NULL)
        return newNode;
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
        head = insert_at_tail(x,head);
    }
    print(head);

    int l,r;
    cin>>l>>r;
    ListNode *rb = reverseBetween(head,l,r);
    print(rb);

    return 0;
}
