#include <iostream>
#define MAX_VAL 1000000
using namespace std;

int getParitialSum(int n)
{
    int val = n;
    while (val)
    {
        n += val % 10;
        val /= 10;
    }
    return n;
}

int getMinValue(int n)
{
    int order = 0;
    int val = n;
    while (val)
    {
        order++;
        val /= 10;
    }
    val = n;
    while (order--)
    {
        val -= 9;
    }
    if (val < 0)
    {
        val = 1;
    }
    return val;
}

int main(void)
{
    int N;
    int minResult = MAX_VAL;
    cin >> N;
    int ret = 0;

    for (int i = getMinValue(N); i < N; ++i)
    {
        int partialSum = getParitialSum(i);
        if (N == partialSum)
        {
            ret = i;
            break;
        }
    }
    cout << ret << endl;
}