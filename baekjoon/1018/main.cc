#include <iostream>
#include <vector>
#define TARGET_BOARD_SIZE 8
#define MAX_VAL TARGET_BOARD_SIZE *TARGET_BOARD_SIZE

using namespace std;
int N, M;
char val;

vector<vector<bool>> board;

int coloringCount(int startRow, int startCol, bool startVal)
{
    bool curRowVal = startVal;
    int count = 0;
    for (int i = 0; i < TARGET_BOARD_SIZE; ++i)
    {
        bool curColVal = curRowVal;
        for (int j = 0; j < TARGET_BOARD_SIZE; ++j)
        {
            if (board[startRow + i][startCol + j] ^ curColVal)
            {
                count++;
            }
            curColVal = !curColVal;
        }
        curRowVal = !curRowVal;
    }
    return count;
}

int main()
{
    cin.sync_with_stdio(false);
    // freopen("./input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        vector<bool> row;
        for (int j = 0; j < M; ++j)
        {
            cin >> val;
            row.push_back(val == 'W' ? true : false);
        }
        board.push_back(row);
    }

    int ret = MAX_VAL;
    for (int i = 0; i < N - TARGET_BOARD_SIZE + 1; ++i)
    {
        for (int j = 0; j < M - TARGET_BOARD_SIZE + 1; ++j)
        {
            ret = min(ret, coloringCount(i, j, true));
            ret = min(ret, coloringCount(i, j, false));
        }
    }
    cout << ret << endl;
}
