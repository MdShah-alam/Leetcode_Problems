#include<bits/stdc++.h>
using namespace std;

string convert(string s, int n)
{
    if(n == 1 || n >= s.size()) return s; // fix: handle edge cases

    string res = "";
    int increment = 2 * (n - 1);

    for(int r = 0; r < n; r++) {
        for(int i = r; i < s.size(); i += increment) {
            res += s[i];
            if(r > 0 && r < n-1 && i + increment - 2*r < s.size()) {
                res += s[i + increment - 2*r];
            }
        }
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<convert(s,n)<<endl;
    return 0;
}
/**

PAYPALISHIRING
4

*/
