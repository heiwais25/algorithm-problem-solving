#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_NUM 987654321
using namespace std;

vector<int> numbers;
vector<int> acc;
vector<int> squareAcc;

int cache[101][11];

// [from, to]
int squaredError(int from, int to)
{
    // Calculate mean
    int sum = 0;
    int squareSum = 0;
    if (from == 0)
    {
        sum = acc[to];
        squareSum = squareAcc[to];
    }
    else
    {
        sum = acc[to] - acc[from - 1];
        squareSum = squareAcc[to] - squareAcc[from - 1];
    }

    int mean = int(0.5 + (double)sum / (to - from + 1));
    return squareSum - 2 * mean * sum + mean * mean * (to - from + 1);
}

int getQuantizeError(int from, int parts)
{
    // 나머지 전체에 대한 합
    int ns = numbers.size();
    if (from == ns)
        return 0;

    if (parts == 0)
        return MAX_NUM;

    int &ret = cache[from][parts];
    if (ret != -1)
        return ret;

    ret = MAX_NUM;
    for (int size = 1; from + size <= ns; ++size)
    {
        ret = min(ret, squaredError(from, from + size - 1) + getQuantizeError(from + size, parts - 1));
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
        int N, numParts;
        cin >> N >> numParts;

        numbers.resize(N);
        acc.resize(N);
        squareAcc.resize(N);

        for (int i = 0; i < N; ++i)
            cin >> numbers[i];

        sort(numbers.begin(), numbers.end());

        acc[0] = numbers[0];
        squareAcc[0] = numbers[0] * numbers[0];
        for (int i = 1; i < N; ++i)
        {
            acc[i] = acc[i - 1] + numbers[i];
            squareAcc[i] = squareAcc[i - 1] + numbers[i] * numbers[i];
        }

        cout << getQuantizeError(0, numParts) << endl;
    }
}