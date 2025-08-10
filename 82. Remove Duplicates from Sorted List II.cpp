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
    if(head == nullptr) return newNode;
    ListNode *temp = head;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next = newNode;
    return head;
}

void print(ListNode *head)
{
    ListNode *temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* deleteDuplicates(ListNode* head)
{
    if(head==nullptr) return head;
    unordered_map<int,int>mp;
    ListNode *temp = head;

    while(temp){
        mp[temp->val]++;
        temp = temp->next;
    }

    ListNode dummy(0);
    ListNode *prev = nullptr;
    dummy.next = head;
    prev = &dummy;
    temp = head;

    while(temp){
        if(mp[temp->val]>1){
            prev->next = temp->next;
            delete(temp);
            temp = prev->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return dummy.next;
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
    head = deleteDuplicates(head);
    print(head);
    return 0;
}
