#include <iostream>
#include <vector>

using namespace std;

int exponential(int A, int factor, int mod)
{
    long long ret = 1L;

    if (factor == 0)
    {
        return 1;
    }
    else if (factor % 2 == 1)
    {
        long long value = exponential(A, (factor - 1) / 2, mod);
        ret = (ret * (((((value * value) % mod)) * A) % mod)) % mod;
    }
    else
    {
        long long value = exponential(A, factor / 2, mod);
        ret = (ret * ((value * value) % mod)) % mod;
    }
    return (int)ret;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int A, B, C;

    cin >> A >> B >> C;
    cout << exponential(A, B, C) << endl;
}