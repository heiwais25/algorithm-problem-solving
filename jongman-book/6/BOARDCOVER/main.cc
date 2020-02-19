#include <iostream>

#define MAX_SIZE 20
#define NUM_DIRECTIONS 4
using namespace std;

int H = 0, W = 0;
bool board[MAX_SIZE][MAX_SIZE];

void getBoard()
{
    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            char cell;
            cin >> cell;
            board[h][w] = cell == '.';
        }
    }
}

int dx[NUM_DIRECTIONS][2] = {
    {1, 1},
    {0, 1},
    {1, 0},
    {0, -1}};

int dy[NUM_DIRECTIONS][2] = {
    {0, 1},
    {1, 1},
    {0, 1},
    {1, 1}};

bool inArea(int y, int x)
{
    return y >= 0 && y < H && x >= 0 && x < W;
}

bool canColor(int y, int x, int dir)
{
    bool ret = true;
    for (int i = 0; i < 2; ++i)
    {
        int curY = y + dy[dir][i];
        int curX = x + dx[dir][i];
        if (!inArea(curY, curX) || !board[curY][curX])
        {
            ret = false;
        }
    }
    return ret;
}

// It should be done after cancolor
void coloring(int y, int x, int dir, bool isFill)
{
    for (int i = 0; i < 2; ++i)
    {
        int newY = y + dy[dir][i];
        int newX = x + dx[dir][i];
        board[newY][newX] = !isFill;
    }
    board[y][x] = !isFill;
}

int countSolution()
{
    // 전체를 확인해서 빈 칸이 있으면 색칠 시도
    int curY = -1, curX = -1;
    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            if (board[h][w])
            {
                curY = h;
                curX = w;
                break;
            }
        }
        if (curX != -1)
        {
            break;
        }
    }

    if (curX == -1)
    {
        return 1;
    }

    int count = 0;
    for (int dir = 0; dir < NUM_DIRECTIONS; ++dir)
    {
        if (canColor(curY, curX, dir))
        {
            coloring(curY, curX, dir, true);
            count += countSolution();
            coloring(curY, curX, dir, false);
        }
    }
    return count;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    while (N--)
    {
        cin >> H >> W;
        getBoard();
        cout << countSolution() << endl;
    }
}