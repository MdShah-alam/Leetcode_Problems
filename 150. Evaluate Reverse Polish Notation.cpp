#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>&v)
{
    int n=v.size();
    stack<int>st;
    for(int i=0;i<n;i++){
        if(v[i]!="+" && v[i]!="-" && v[i]!="*" && v[i]!="/"){
            st.push(stoi(v[i]));
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(v[i]=="+"){
                st.push(a+b);
            }
            else if(v[i]=="-")
                st.push(b-a);
            else if(v[i]=="*")
                st.push(a*b);
            else
                st.push(b/a);
        }
    }
    return st.top();
}

int main()
{
    int n;
    cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    cout<<evalRPN(s)<<endl;
    return 0;
}
/**

5
2 1 + 3 *

*/
