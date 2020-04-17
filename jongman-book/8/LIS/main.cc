#include <iostream>
#include <vector>
#include <cstring>
#define MAX_NUMBER 500

using namespace std;

vector<int> numbers;
int cache[MAX_NUMBER + 2];
int lis(int cur)
{
    int &ret = cache[cur + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    int ns = numbers.size();
    for (int i = cur + 1; i < ns; ++i)
        if (cur == -1 || numbers[i] > numbers[cur])
            ret = max(ret, 1 + lis(i));

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
        int N;
        cin >> N;

        numbers.resize(N);
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            cin >> *it;
        }

        cout << lis(-1) - 1 << endl;
    }
}