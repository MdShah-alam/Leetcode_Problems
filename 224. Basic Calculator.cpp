#include<bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    long result = 0;
    long num = 0;
    int sign = 1;
    stack<int>st;

    for(int i=0;i<s.size();i++){
        if(isdigit(ch))
            num = num*10+(ch-'0');

        else if(ch=='+'){
            result+=sign*num;
            num=0;
            sign=1;
        }
        else if(ch=='-'){
            result+=sign*num;
            num=0;
            sign=-1;
        }
        else if(ch=='('){
            st.push(result);
            st.push(sign);
            result=0;
            sign=1;
        }
        else if(ch==')'){
            result+=sign * num;
            num = 0;
            result *= st.top();
            st.pop();
            result += st.top();
            st.pop();
        }
    }
    if(num!=0) result+=sign*num;
    return result;
}

int main()
{
    string s;
    cin>>s;
    cout<<calculate(s)<<endl;
    return 0;
}
