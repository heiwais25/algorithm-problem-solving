#include <iostream>
#include <vector>

using namespace std;

#define PRIME 1000000007
#define MOD_BY_MAX(a) ((a) % PRIME)
#define MOD_MULTIPLY(a, b) ((((a) % PRIME) * ((b) % PRIME)) % PRIME)

long long factorialMOD(int from, int to)
{
    long long ret = 1L;
    for (long long i = from; i <= to; ++i)
    {
        ret = (ret * i) % PRIME;
    }
    return ret;
}

// Assume k is positive
long long exponentialBySquare(int val, int k)
{
    long long ret = 1L;
    if (k == 0)
        return ret;
    if (k % 2 == 1)
    {
        long long squared = exponentialBySquare(val, (k - 1) / 2);
        ret = MOD_MULTIPLY(ret, MOD_MULTIPLY(MOD_MULTIPLY(squared, squared), val));
    }
    else
    {
        long long squared = exponentialBySquare(val, k / 2);
        ret = MOD_MULTIPLY(ret, MOD_MULTIPLY(squared, squared));
    }
    // cout << val << " " << k << endl;
    return ret;
}

long long binomialCoeff(int N, int K)
{
    long long numerator = factorialMOD(N - K + 1, N);
    long long denominator = exponentialBySquare(factorialMOD(1, K), PRIME - 2);
    return MOD_MULTIPLY(numerator, denominator);
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    cout << binomialCoeff(N, K) << endl;
}