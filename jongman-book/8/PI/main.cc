#include <iostream>
#include <vector>
#include <cstring>
#define MAX_SIZE 10000
#define MAX_VAL 123456789

using namespace std;

int cache[MAX_SIZE + 2];
string numbers;

// [from, to] 에서의 최소 값
int classify(int from, int to)
{
    int size = to - from + 1;
    string cur = numbers.substr(from, size);
    if (cur == string(cur.size(), cur[0]))
        return 1;

    bool progressive = true, alternative = true;
    for (int i = 0; i < size - 1; ++i)
        if (cur[i + 1] - cur[i] != cur[1] - cur[0])
            progressive = false;

    if (progressive && abs(cur[1] - cur[0]) == 1)
        return 2;

    for (int i = 0; i < size; ++i)
        if (cur[i] != cur[i % 2])
            alternative = false;

    if (alternative)
        return 4;

    if (progressive)
        return 5;

    return 10;
}

// 현재 위치에서 보일 수 있는 최소의 조합
int pi(int cur)
{
    int ns = numbers.size();
    if (cur == ns)
        return 0;

    int &ret = cache[cur];
    if (ret != -1)
        return ret;

    ret = MAX_VAL;
    for (int i = 3; i <= 5; ++i)
    {
        if (cur + i <= ns)
        {
            ret = min(ret, pi(cur + i) + classify(cur, cur + i - 1));
        }
    }
    return ret;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int C;
    cin >> C;
    while (C--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> numbers;
        cout << pi(0) << endl;
    }
}