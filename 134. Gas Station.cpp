#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n=gas.size(),curr=0,currFast=0,total=0,start=0;
    for(int i=0;i<n;i++){
        total = total+(gas[i]-cost[i]);
        curr = curr+(gas[i]-cost[i]);
        if(curr<0){
            curr=0;
            start=i+1;
        }
    }
    if(total>=0) return start;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>gas(n),cost(n);
    for(int i=0;i<n;i++)
        cin>>gas[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    cout<<canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
/**

5
1 2 3 4 5
3 4 5 1 2

*/
