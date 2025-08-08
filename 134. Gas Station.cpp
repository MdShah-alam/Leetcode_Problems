#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int total_tank=0, curr_tank=0, start_station=0;
    for(int i=0;i<gas.size();i++){
        int diff = gas[i]-cost[i];
        total_tank+=diff;
        curr_tank+=diff;
        if(curr_tank<0){
            curr_tank=0;
            start_station=i+1;
        }
    }
    return total_tank>=0 ? start_station : -1;
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
