#include <iostream>
#include <limits>
#include <vector>
#include <cstring>
#define MAX_SIZE 100
using namespace std;

const long long NEG_INF = numeric_limits<long long>::min();

vector<int> A, B;
int cache[MAX_SIZE + 1][MAX_SIZE + 1];

int jlis(int aIdx, int bIdx)
{
    int &ret = cache[aIdx + 1][bIdx + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    long long a = aIdx == -1 ? NEG_INF : A[aIdx];
    long long b = bIdx == -1 ? NEG_INF : B[bIdx];
    long long maxElement = max(a, b);

    int as = A.size(), bs = B.size();

    for (int i = aIdx + 1; i < as; ++i)
        if (A[i] > maxElement)
            ret = max(ret, 1 + jlis(i, bIdx));

    for (int i = bIdx + 1; i < bs; ++i)
        if (B[i] > maxElement)
            ret = max(ret, 1 + jlis(aIdx, i));

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
        int a_size, b_size;
        cin >> a_size >> b_size;
        A.resize(a_size, 0);
        B.resize(b_size, 0);
        for (auto it = A.begin(); it != A.end(); ++it)
            cin >> *it;
        for (auto it = B.begin(); it != B.end(); ++it)
            cin >> *it;

        cout << jlis(-1, -1) - 1 << endl;
    }
}