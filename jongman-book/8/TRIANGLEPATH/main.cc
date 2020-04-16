#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_SIZE 100

int cache[MAX_SIZE + 1][MAX_SIZE + 1];

int maxSum(const vector<vector<int>> &board, int y, int x)
{
    int &ret = cache[y][x];
    int size = board.size();
    if (ret != -1)
        return ret;
    if (y == size - 1)
    {
        return ret = board[y][x];
    }

    return ret = board[y][x] + max(maxSum(board, y + 1, x + 1), maxSum(board, y + 1, x));
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

        int count = 1;
        for (auto rowIt = board.begin(); rowIt != board.end(); rowIt++)
        {
            for (int i = 0; i < count; ++i)
            {
                cin >> (*rowIt)[i];
            }
            count++;
        }

        memset(cache, -1, sizeof(cache));
        cout << maxSum(board, 0, 0) << endl;
    }
}