#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& v)
{
    for(int i=0,j=1;j<v.size();j++){
        int k=0;
        if(v[i]==v[j]){
            k++;
            while(v[i]==v[j]){
                j++;
                k++;
            }
        }
        if(k>2){
            for(int a=0;a<k-2;a++){
                auto it = find(v.begin(), v.end(), v[i]);
                    v.erase(it);
            }
        }
        i=j;
    }
    return v.size();
}

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    cout<<removeDuplicates(v)<<endl;
    return 0;
}
