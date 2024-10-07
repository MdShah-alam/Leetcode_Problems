#include<bits/stdc++.h>
using namespace std;

void createParantheses(int open, int close , string current , vector<string>&result)
{
    if(open==0 && close==0){
        result.push_back(current);
        return ;
    }
    if(open>0)
        createParantheses(open-1,close , current+"(" , result);
        cout<<open<<" "<<close<<" "<<current<<endl;
    if(close>open)
        createParantheses(open ,close-1 , current+")" , result);
        cout<<open<<" "<<close<<" - "<<current<<endl;

}
vector<string> generateParenthesis(int n)
{
    vector<string>result;
    createParantheses(n,n,"",result);
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<string>v=generateParenthesis(n);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
