#include <vector>
#include <iostream>
#include <string>
#define BOARD_SIZE 5
#define MAX_LENGTH 10

// ! Important point is use memoization

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
string targetWord;
char board[BOARD_SIZE][BOARD_SIZE];
bool isVisited[BOARD_SIZE][BOARD_SIZE][MAX_LENGTH];

bool inArea(int row, int col)
{
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void getBoard()
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        string rowString;
        cin >> rowString;
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            board[row][col] = rowString[col];
        }
    }
}

void init()
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
            for (int i = 0; i < MAX_LENGTH; ++i)
            {
                isVisited[row][col][i] = false;
            }
        }
    }
}

bool hasWord(int row, int col, int wordIdx)
{
    isVisited[row][col][wordIdx] = true;
    if (board[row][col] != targetWord[wordIdx])
    {
        return false;
    }

    if (wordIdx + 1 == targetWord.size())
    {
        return true;
    }

    bool ret = false;
    // Check for each direction
    for (int dir = 0; dir < 8; dir++)
    {
        int newRow = row + dy[dir];
        int newCol = col + dx[dir];
        if (inArea(newRow, newCol) && !isVisited[newRow][newCol][wordIdx + 1])
        {
            ret = hasWord(newRow, newCol, wordIdx + 1);
            if (ret)
                break;
        }
    }
    return ret;
}

bool findSolution()
{
    bool ret = false;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            ret = hasWord(row, col, 0);
            if (ret)
            {
                return ret;
            }
        }
    }
    return ret;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    while (N--)
    {
        getBoard();
        // Get

        int wordCount;
        cin >> wordCount;
        while (wordCount--)
        {
            cin >> targetWord;
            init();
            string result = findSolution() ? "YES" : "NO";
            cout << targetWord << " " << result << endl;
        }
    }
}