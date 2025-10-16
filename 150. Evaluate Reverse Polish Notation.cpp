#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>&v)
{
    stack<int>st;
    for(string s: v){
        if(s=="+" || s=="-" || s=="/" || s=="*"){
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if(s=="+") st.push(a+b);
            else if(s=="-") st.push(a-b);
            else if(s=="*") st.push(a*b);
            else st.push(a/b);
        }
        else
            st.push(stoi(s));
    }
    return st.top();
}

int main()
{
    int n;
    cin>>n;
    vector<string>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<evalRPN(v)<<endl;
    return 0;
}
/**

13
10 6 9 3 + -11 * / * 17 + 5 +

*/
