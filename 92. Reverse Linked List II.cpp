#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        this->val=x;
        this->next = NULL;
    }
};

ListNode *insert_ta_tail(ListNode *head, int x)
{
    ListNode *newNode = new ListNode(x);
    if(!head) return newNode;
    ListNode *temp=head;
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

ListNode *help(ListNode *head, int l, int r)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr && l<=r){
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        l++;
    }
    head->next = curr;
    return prev;
}
ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if(left==right) return head;
    else if(left==1){
        return help(head, left, right);
    }
    else{
        ListNode *temp = head;
        int n=1;
        ListNode *temp3=temp;
        while(n!=left && temp!=NULL){
            n++;
            temp3 = temp;
            temp = temp->next;
        }
        ListNode *temp2 = help(temp,left, right);
        temp3->next = temp2;
    }
    return head;
}

int main()
{
    int n;
    cin>>n;
    ListNode *head = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        head = insert_ta_tail(head,x);
    }
    print(head);
    int l,r;
    cin>>l>>r;
    ListNode *temp = reverseBetween(head, l,r);
    print(temp);

    return 0;
}
/**

5
1 2 3 4 5


*/
