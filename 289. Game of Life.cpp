#include<bits/stdc++.h>
using namespace std;

int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
bool isValid(int n, int m, int new_x,int new_y)
{
    if(new_x<0 || new_x>=n)
        return false;
    if(new_y<0 || new_y>=m)
        return false;
    return true;
}
void gameOfLife(vector<vector<int>>&board)
{
    vector<vector<int>>v=board;
    int n=board.size();
    int m=board[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int lives=0;
            int dies=0;
            for(int a=0;a<8;a++){
                int new_x=dx[a]+i;
                int new_y=dy[a]+j;
                if(isValid(n,m,new_x,new_y)){
                    if(board[new_x][new_y]==0)
                        dies++;
                    else
                        lives++;
                }
            }
            if(board[i][j]==1){
                if(lives==2 || lives==3)
                    v[i][j]=1;
                else
                    v[i][j]=0;
            }
            else{
                if(lives==3)
                    v[i][j]=1;
                else
                    v[i][j]=0;
            }
        }
    }
    board=v;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
    }
    gameOfLife(v);
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/**

4 3
0 1 0
0 0 1
1 1 1
0 0 0

*/
