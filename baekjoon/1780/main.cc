#include <iostream>
#include <vector>

#define UNIT 3

using namespace std;

vector<vector<int>> board;

struct PageCount
{
    int minus = 0;
    int zero = 0;
    int plus = 0;

    void operator+=(const PageCount &pageCount)
    {
        minus += pageCount.minus;
        zero += pageCount.zero;
        plus += pageCount.plus;
    }
};

PageCount solve(int y, int x, int size)
{
    // base (check same)
    bool isSame = true;

    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (board[i][j] != board[y][x])
            {
                isSame = false;
            }
        }
    }

    PageCount retCount;

    if (isSame)
    {
        if (board[y][x] == 1)
        {
            retCount.plus++;
        }
        else if (board[y][x] == 0)
        {
            retCount.zero++;
        }
        else
        {
            retCount.minus++;
        }
        return retCount;
    }

    // Divide
    int newSize = size / UNIT;
    for (int i = 0; i < UNIT; ++i)
    {
        for (int j = 0; j < UNIT; ++j)
        {
            retCount += solve(y + newSize * i, x + newSize * j, newSize);
        }
    }

    return retCount;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        vector<int> row;
        for (int j = 0; j < N; j++)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        board.push_back(row);
    }
    PageCount count = solve(0, 0, board.size());
    cout << count.minus << endl;
    cout << count.zero << endl;
    cout << count.plus << endl;
}