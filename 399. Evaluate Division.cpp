#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<pair<string,double>>>graph;
double dfs(string curr, string target, unordered_set<string>&visited, double val)
{
    if(graph.find(curr)==graph.end()) return -1.0;
    if(curr==target) return val;

    visited.insert(curr);

    for(auto &neighbor : graph[curr]){
        if(!visited.count(neighbor.first)){
            double result = dfs(neighbor.first, target, visited, val*neighbor.second);
            if(result != -1.0)
                return result;
        }
    }
    return -1.0;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    for(int i=0;i<equations.size(); i++){
        string a = equations[i][0];
        string b = equations[i][1];
        double val = values[i];
        graph[a].push_back({b,val});
        graph[b].push_back({a,1.0/val});
    }
    vector<double>ans;
    for(auto & query : queries){
        string num = query[0];
        string den = query[1];
        unordered_set<string>visited;
        if(graph.find(num)==graph.end() || graph.find(den)==graph.end())
            ans.push_back(-1.0);
        else
            ans.push_back(dfs(num , den, visited, 1.0));
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<string>>equations(n, vector<string>(2));
    for(int i=0;i<n;i++){
        cin>>equations[i][0]>>equations[i][1];
    }

    vector<double>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int m;
    cin>>m;
    vector<vector<string>>queries(m,vector<string>(2));
    for(int i=0;i<m;i++)
        cin>>queries[i][0]>>queries[i][1];

    vector<double>result = calcEquation(equations,v,queries);
    for(double res : result)
        cout<<res<<" ";
    cout<<endl;
    return 0;
}

/**

3
a b
b c
bc cd

1.5 2.5 5.0

4
a c
c b
bc cd
cd bc

*/
