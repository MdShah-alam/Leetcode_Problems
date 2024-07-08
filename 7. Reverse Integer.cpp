#include<bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int d=0 , m=0;
    while(x){
        d=x%10;
        if(m>INT_MAX/10 || m<INT_MIN)
            return 0;
        m=m*10+d;
        x=x/10;
    }
    return m;
}

int main()
{
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
    cout<<INT_MAX<<endl<<INT_MIN<<endl;
    return 0;
}

////  -2147483412
