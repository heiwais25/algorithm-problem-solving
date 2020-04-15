#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getMatrix(int M, int K)
{
    vector<vector<int>> a;
    for (int i = 0; i < M; ++i)
    {
        vector<int> row;
        for (int j = 0; j < K; ++j)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        a.push_back(row);
    }
    return a;
}

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b[0].size(); ++j)
        {
            for (int k = 0; k < b.size(); ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int M, K;
    cin >> M >> K;
    auto A = getMatrix(M, K);
    cin >> M >> K;
    auto B = getMatrix(M, K);

    auto ret = multiply(A, B);
    for (auto row : ret)
    {
        for (int i = 0; i < row.size(); ++i)
        {
            cout << row[i];
            if (i != row.size() - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}