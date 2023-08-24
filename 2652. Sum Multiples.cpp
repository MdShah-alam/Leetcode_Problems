#include<bits/stdc++.h>
using namespace std;

int sumOfMultiples(int n)
{
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(i%3==0 || i%5==0 || i%7==0){
            if (find(v.begin(), v.end(), i) == v.end())
                v.push_back(i);
        }
    }

    int sum = 0;
    for(int i=0;i<v.size();i++)
        sum += v[i];
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<sumOfMultiples(n)<<endl;
    return 0;
}
