#include<bits/stdc++.h>
using namespace std;

int snakesAndLadders(vector<vector<int>>& board)
{
    int n = board.size();
    auto getCoordinates = [&](int square) {
        int row = n - 1 - (square - 1) / n;
        int col = (square - 1) % n;
        if ((n - row) % 2 == 0)
            col = n - 1 - col;
        return make_pair(row, col);
    };
    queue<pair<int, int>> q;
    vector<bool> visited(n * n + 1, false);
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [square, moves] = q.front();
        q.pop();
        if (square == n * n) {
            return moves;
        }
        for (int nextSquare = square + 1; nextSquare <= min(square + 6, n * n); ++nextSquare) {
            auto [row, col] = getCoordinates(nextSquare);
            int destination = (board[row][col] == -1) ? nextSquare : board[row][col];
            if (!visited[destination]) {
                visited[destination] = true;
                q.push({destination, moves + 1});
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    cout <<snakesAndLadders(board)<< endl;
    return 0;
}

