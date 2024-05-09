#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode * next;
    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class TreeNode
{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* creatTree(int l , int r , vector<int>v)
{
    TreeNode * root= NULL;
    if(l>r) return root;

    int mid = l +(r-l)/2;
    root = new TreeNode(v[mid]);

    root->left = creatTree(l , mid-1 , v);
    root->right = creatTree(mid+1 , r , v);

    return root;
}

TreeNode * constructTree(ListNode* head)
{
    TreeNode * root=NULL;
    if(head == NULL) return root;

    vector<int>v;
    while(head){
        v.push_back(head->data);
        head=head->next;
    }

    root = creatTree(0 , v.size()-1 , v);
    return root;
}

ListNode* constructList(ListNode *&head , int data)
{
    if(head == NULL)
        return head = new ListNode(data);

    ListNode * presentNode = head;

    while(presentNode->next!=NULL){
        presentNode = presentNode->next;
    }
    ListNode *newNode = new ListNode(data);
    presentNode->next = newNode;
    return head;
}

void print(TreeNode* root)
{
    if(root==NULL)
        return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin>>n;
    ListNode * head=NULL;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = constructList(head , a);
    }
    TreeNode *root = constructTree(head);

    cout<<endl;
    print(root);
    cout<<endl;

    return 0;
}
/**

5
1 2 3 4 5

*/
