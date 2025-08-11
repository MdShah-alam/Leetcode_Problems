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

ListNode *insert_at_tail(ListNode *head , int val)
{
    ListNode *newNode = new ListNode(val);
    if(head == nullptr) return newNode;

    ListNode *temp = head;
    while(temp->next!=nullptr)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
ListNode *getKthNode(ListNode *temp , int k)
{
    k-=1;
    while(temp!=nullptr && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
void reverseSegment(ListNode* &start, ListNode* end) {
    ListNode* prev = nullptr;
    ListNode* curr = start;
    ListNode* stop = end->next;

    while (curr != stop) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *temp = head;
    ListNode *prevList = nullptr;

    while (temp) {
        ListNode *kthnode = getKthNode(temp, k);
        if (!kthnode) {
            if (prevList) prevList->next = temp;
            break;
        }
        ListNode *nextNode = kthnode->next;
        ListNode* tail = temp;
        reverseSegment(temp, kthnode);

        if (!prevList)
            head = kthnode;
        else
            prevList->next = kthnode;

        tail->next = nextNode;
        prevList = tail;
        temp = nextNode;
    }
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
    ListNode *head = nullptr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head, a);
    }
    print(head);
    head = reverseKGroup(head , 4);
    print(head);

    return 0;
}

/**

10
1 2 3 4 5 6 7 8 9 10

*/
