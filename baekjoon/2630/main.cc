#include <iostream>
#include <vector>
using namespace std;

struct PaperCount
{
    int white = 0;
    int blue = 0;

    void operator+=(const PaperCount &rhs)
    {
        white += rhs.white;
        blue += rhs.blue;
    }

    void print()
    {
        cout << white << " " << blue << endl;
    }
};

PaperCount solve(const vector<vector<bool>> &board, int y, int x, int size)
{
    // base
    // 현재가 전부 같은 색인지 확인
    bool isSameColor = true;
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (board[i][j] ^ board[y][x])
            {
                isSameColor = false;
            }
        }
    }
    PaperCount count;
    if (isSameColor)
    {
        if (board[y][x])
        {
            count.blue++;
        }
        else
        {
            count.white++;
        }
        return count;
    }

    int half = size / 2;
    count += solve(board, y, x, half);
    count += solve(board, y + half, x, half);
    count += solve(board, y, x + half, half);
    count += solve(board, y + half, x + half, half);
    return count;
}

int main(void)
{

    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    // 1. 분할
    // 2. 병합
    // 3. 풀이 (base에서)
    vector<vector<bool>> board;
    for (int i = 0; i < N; ++i)
    {
        vector<bool> row;
        for (int j = 0; j < N; ++j)
        {
            int val;
            cin >> val;
            row.push_back(val == 1);
        }
        board.push_back(row);
    }

    PaperCount count = solve(board, 0, 0, board.size());

    cout << count.white << endl;
    cout << count.blue << endl;
}