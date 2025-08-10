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
    if(head==nullptr) return newNode;

    ListNode *temp = head;

    while(temp->next!=nullptr)
        temp=temp->next;

    temp->next=newNode;
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head=nullptr;
    int n=0;
    while(l1!=nullptr && l2!=nullptr){
        n = n + l1->val+l2->val;
        l1=l1->next;
        l2=l2->next;
        int m = n%10;
        n=n/10;
        head = insert_at_tail(head, m);
    }
    while(l1!=nullptr){
        n = n + l1->val;
        l1 = l1->next;
        int m = n%10;
        n=n/10;
        head = insert_at_tail(head, m);
    }

    while(l2!=nullptr){
        n = n + l2->val;
        l2=l2->next;
        int m = n%10;
        n=n/10;
        head = insert_at_tail(head, m);
    }
    while(n){
        head = insert_at_tail(head , n%10);
        n = n / 10;
    }
    return head;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    ListNode *l1=nullptr, *l2=nullptr;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        l1=insert_at_tail(l1,a);
    }

    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        l2=insert_at_tail(l2,a);
    }

    print(l1);
    cout<<endl;
    print(l2);
    cout<<endl;

    ListNode *head = addTwoNumbers(l1,l2);
    print(head);
    cout<<endl;

    return 0;
}

/**

3 4
2 4 9
5 6 4 9

*/
