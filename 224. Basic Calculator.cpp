#include<bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    stack<int>st;
    int cur=0,res=0,sign=1;
    for(char ch : s){
        if(isdigit(ch)){
            cur = cur*10 + (ch - '0');
        }
        else if(ch=='+' || ch=='-'){
            res+=sign*cur;
            sign = (ch == '-') ? -1 : 1;
            cur=0;
        }
        else if(ch=='('){
            st.push(res);
            st.push(sign);
            sign=1;
            res=0;
        }
        else if(ch==')'){
            res+=sign*cur;
            res*=st.top();
            st.pop();
            res+=st.top();
            st.pop();
            cur=0;
        }
    }
    res += sign * cur; // last number
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<calculate(s)<<endl;
    return 0;
}
