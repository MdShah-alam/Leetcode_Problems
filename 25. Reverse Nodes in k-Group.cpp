#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode * next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode * insert_at_tail(ListNode *& head , int val)
{
    ListNode * newnode = new ListNode(val);
    if(head == NULL)
        return head = newnode;

    ListNode * temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void printList(ListNode * head)
{
    ListNode * temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode * reverse_k_group(ListNode * head , int k)
{
    if(head == NULL || k == 1)
        return head;
    ListNode * dummy = new ListNode(0);
    dummy->next = head ;
    ListNode *cur=dummy , *nxt = dummy , *pre = dummy;
    int cont = 0;

    while(cur->next != NULL){
        cur = cur->next;
        cont++;
    }
    while(cont >= k){
        cur = pre->next;
        nxt = cur->next;
        for(int i=1;i<k;i++){
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
        }
        pre = cur;
        cont-=k;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin>>n;
    ListNode * head = NULL;

    for(int i=0; i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head , a);
    }
    printList(head);
    int k;
    cin>>k;
    ListNode * hed = reverse_k_group(head , k);
    printList(hed);
}
