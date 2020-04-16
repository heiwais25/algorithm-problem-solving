#include <iostream>
#include <vector>

using namespace std;

bool jump(const vector<vector<int>> &board, int y, int x, vector<vector<int>> &cache)
{
    int boardSize = board.size();
    // Base exception case
    if (y >= boardSize || x >= boardSize)
    {
        return false;
    }

    if (cache[y][x] != -1)
    {
        return cache[y][x] == 1;
    }

    int &ret = cache[y][x];

    // Solution
    if (y == boardSize - 1 && x == boardSize - 1)
    {
        ret = 1;
        return true;
    }

    int step = board[y][x];
    ret = jump(board, y + step, x, cache) || jump(board, y, x + step, cache) ? 1 : 0;
    return ret == 1;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int C;
    cin >> C;
    while (C--)
    {
        int N;
        cin >> N;

        vector<vector<int>> board(N, vector<int>(N));
        vector<vector<int>> cache(N, vector<int>(N, -1));

        for (auto rowIt = board.begin(); rowIt != board.end(); rowIt++)
        {
            for (auto colIt = rowIt->begin(); colIt != rowIt->end(); colIt++)
            {
                cin >> *colIt;
            }
        }

        string ret = jump(board, 0, 0, cache) ? "YES" : "NO";
        cout << ret << endl;
    }
}