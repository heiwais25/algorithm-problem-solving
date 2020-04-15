#include <iostream>
#include <vector>

#define MOD 1000

using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix &a, const Matrix &b)
{
    Matrix ret(a.size(), vector<long long>(b[0].size()));

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b[0].size(); ++j)
        {
            for (int k = 0; k < a[0].size(); ++k)
            {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}

Matrix square(const Matrix &matrix, long long power)
{
    Matrix ret = matrix;
    if (power == 1)
    {
        return ret;
    }
    else if (power % 2 == 1)
    {
        Matrix val = square(matrix, (power - 1) / 2);
        return multiply(ret, multiply(val, val));
    }
    else
    {
        Matrix val = square(matrix, (power) / 2);
        return multiply(val, val);
    }
}

void printMatrix(Matrix &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            cout << matrix[i][j];
            if (j < matrix[0].size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int A;
    long long B;
    cin >> A >> B;

    Matrix matrix(A, vector<long long>(A, 0));

    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < A; ++j)
        {
            long long val;
            cin >> val;
            matrix[i][j] = val % MOD;
        }
    }

    Matrix ret = square(matrix, B);
    printMatrix(ret);
}