#include<bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int a=0,b=0;
    while(x){
        a=x%10;
        b=b*10+a;
        x=x/10;
    }
    return (b < INT_MIN || b > INT_MAX) ? b : 0;
}

int main()
{
    int n;
    cin>>n;
    cout<<reverse(n)<<endl;
    return 0;
}
