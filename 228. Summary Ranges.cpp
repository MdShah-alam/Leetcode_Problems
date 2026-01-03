#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& v)
{
    vector<string>ans;
    int n = v.size();
    string s = to_string(v[0]);
    bool found=true;
    for(int i=1;i<v.size();i++){
        if(v[i-1]==v[i]-1 && found){
            s+="->";
            found=false;
        }
        else if(v[i-1]==v[i]-1) continue;
        else{
            if(i==1 || found)
                ans.push_back(s);
            else{
                s+=to_string(v[i-1]);
                ans.push_back(s);
            }
            s = to_string(v[i]);
            found=true;
        }
    }
    if(found) ans.push_back(s);
    else ans.push_back(s+=to_string(v[n-1]));
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<string>sk = summaryRanges(v);
    for(string s : sk)
        cout<<s<<endl;
    return 0;
}
/**

6
0 1 2 4 5 7

7
0 2 3 4 6 8 9

*/
