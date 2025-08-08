#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& v)
{
    int n = v.size();
    int jump=0, currEnd =0 , currFarthest =0;
    for(int i=0;i<n-1;i++){
        currFarthest = max(currFarthest , i+v[i]);
        if(currEnd==i){
            currEnd=currFarthest;
            jump++;
        }
    }
    return jump;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<jump(v)<<endl;
    return 0;
}
/**

5
2 3 1 1 4

5
3 2 1 0 4

*/
