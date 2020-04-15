#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> board;

string solve(int y, int x, int size)
{
    // base (check same)
    bool isSame = true;

    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (board[i][j] ^ board[y][x])
            {
                isSame = false;
            }
        }
    }

    if (isSame)
    {
        return board[y][x] ? "1" : "0";
    }

    // Divide
    string ret = "(";
    int half = size / 2;
    ret += solve(y, x, half);
    ret += solve(y, x + half, half);
    ret += solve(y + half, x, half);
    ret += solve(y + half, x + half, half);

    return ret + ")";
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        vector<bool> row;
        for (int j = 0; j < N; j++)
        {
            char val;
            cin >> val;
            row.push_back(val == '1');
        }
        board.push_back(row);
    }

    cout << solve(0, 0, board.size()) << endl;
}