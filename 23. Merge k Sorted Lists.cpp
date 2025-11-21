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

ListNode *insert_at_tail(int val, ListNode *root)
{
    ListNode *newNode = new ListNode(val);
    if(!root) return newNode;
    ListNode *temp = root;
    while(temp->next)
        temp = temp->next;
    temp->next = newNode;
    return root;
}
void print(vector<ListNode*>v, int k)
{
    for(int i=0;i<k;i++){
        ListNode *root = v[i];
        while(root){
            cout<<root->val<<" ";
            root = root->next;
        }
        cout<<endl;
    }
}
ListNode *sortTwoList(ListNode *head1, ListNode *head2)
{
    if(!head1) return head2;
    if(!head2) return head1;
    ListNode* head = NULL;
    if(head1->val>head2->val){
        head = head2;
        head2 = head2->next;
    }
    else{
        head = head1;
        head1 = head1->next;
    }
    ListNode *temp=head;
    while(head1 && head2){
        if(head1->val>head2->val){
            temp->next = head2;
            head2 = head2->next;
        }
        else{
            temp->next = head1;
            head1 = head1->next;
        }
        temp = temp->next;
    }
    while(head1){
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }
    while(head2){
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }
    return head;
}
ListNode* mergeKLists(vector<ListNode*>&v)
{
    if(v.size()==0) return NULL;
    ListNode *head = v[0];
    int n = v.size();
    for(int i=1;i<n;i++){
        head = sortTwoList(head, v[i]);
    }
    return head;
}
void print2(ListNode *root)
{
    while(root){
        cout<<root->val<<" ";
        root = root->next;
    }
    cout<<endl;
}
int main()
{
    int k;
    cin>>k;
    vector<ListNode*>v;
    int i=0;
    while(k>i){
        ListNode *root = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            root = insert_at_tail(x,root);
        }
        v.push_back(root);
        i++;
    }
    cout<<endl;
    print(v,k);
    ListNode *rot = mergeKLists(v);
    print2(rot);
}
/**

3
3
1 4 5
3
1 3 4
2
2 6

*/
