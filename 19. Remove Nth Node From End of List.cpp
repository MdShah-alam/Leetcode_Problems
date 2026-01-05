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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(!head) return head;
    int m=0;
    ListNode *temp = head;
    while(temp){
        m++;
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    n = m - n;
    cout<<n<<" "<<m<<endl;
    if(n==0) return head->next;
    int x=0;
    ListNode *prev = nullptr, *curr = head;
    while(x!=n && curr){
        x++;
        prev = curr;
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    if(curr->next) prev->next = curr->next;
    else prev->next = nullptr;
    delete(curr);
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
    int k;
    cin>>k;
    ListNode* hed = removeNthFromEnd(head,k);
    print(hed);
    return 0;
}
/**

5
1 2 3 4 5


*/
