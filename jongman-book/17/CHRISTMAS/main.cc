#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 100000;
const long long MOD = 20091101;

int N, K;

vector<int> updateInput()
{
  cin >> N >> K;

  vector<int> aSum(N + 1);

  aSum[0] = 0;

  for (int i = 0; i < N; ++i)
  {
    int val;
    cin >> val;
    aSum[i + 1] = (aSum[i] + val) % K;
  }

  return aSum;
}

int waysToBuy(vector<int> &aSum)
{
  int ret = 0;
  vector<long long> count(K, 0);
  for (int i = 0; i < aSum.size(); ++i)
    count[aSum[i]]++;

  for (int i = 0; i < K; ++i)
    if (count[i] >= 2)
      ret = (ret + (count[i] * (count[i] - 1)) / 2) % MOD;

  return ret;
}

int maxBuys(vector<int> &aSum)
{
  vector<int> ret(aSum.size(), 0);

  vector<int> prev(K, -1);

  for (int i = 0; i < aSum.size(); ++i)
  {
    if (i > 0)
    {
      ret[i] = ret[i - 1];
    }
    else
    {
      ret[i] = 0;
    }

    int loc = prev[aSum[i]];
    if (loc != -1)
    {
      ret[i] = max(ret[i], ret[loc] + 1);
    }

    prev[aSum[i]] = i;
  }

  return ret.back();
}

int main(void)
{
  cin.sync_with_stdio(false);
  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {

    vector<int> aSum = updateInput();

    cout << waysToBuy(aSum) << " " << maxBuys(aSum) << endl;
  }
}