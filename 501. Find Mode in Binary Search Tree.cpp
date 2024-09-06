#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void print(TreeNode* root)
{
    if(root==NULL)
        return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

void traversal(TreeNode *root, unordered_map<int,int>&mp)
{
    if(root==NULL)
        return ;
    mp[root->val]++;
    traversal(root->left,mp);
    traversal(root->right,mp);
}
vector<int> findMode(TreeNode* root)
{
    unordered_map<int,int>mp;
    traversal(root,mp);

    priority_queue<pair<int,int>>pq;
    for(auto x : mp){
        pq.push({x.second,x.first});
    }

    vector<int>ans;
    int freq=pq.top().first;
    while(!pq.empty() && freq==pq.top().first){
        auto c = pq.top();
        pq.pop();
        ans.push_back(c.second);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root=new TreeNode(n);

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode *present=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        TreeNode *n1=NULL;
        TreeNode *n2=NULL;

        if(x!=-1)
            n1=new TreeNode(x);
        if(y!=-1)
            n2=new TreeNode(y);

        present->left=n1;
        present->right=n2;

        if(n1!=NULL)
            q.push(n1);
        if(n2!=NULL)
            q.push(n2);
    }

    print(root);
    cout<<endl;
    vector<int>v=findMode(root);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
/**

-4
2 7
3 5 6 9
-1 -1 -1 -1 -1 -1 -1 -1

3
9 20
-1 -1 15 7
-1 -1 -1 -1

1
1 2
1 -1 2 -1
-1 -1 2 -1
-1 -1

1
0 1
0 0 1 1
0 -1 -1 -1 -1 -1 -1 -1
-1 -1

*/



