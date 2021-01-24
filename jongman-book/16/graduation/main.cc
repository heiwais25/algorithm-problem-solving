#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_N = 12;
const int MAX_M = 10;

int C, N, K, M, L;

int prerequisites[MAX_N + 1];
int classes[MAX_M + 1];
int caches[MAX_M + 1][1 << MAX_N];

void updateInput()
{
  memset(prerequisites, 0, sizeof(int) * (MAX_N + 1));
  memset(classes, 0, sizeof(int) * (MAX_M + 1));
  int maxJ = 1 << MAX_N;
  for (int i = 0; i < MAX_M + 1; ++i)
  {
    for (int j = 0; j < maxJ; ++j)
    {
      caches[i][j] = -1;
    }
  }

  cin >> N >> K >> M >> L;
  for (int i = 0; i < N; ++i)
  {
    int R;
    cin >> R;
    for (int j = 0; j < R; ++j)
    {
      int val;
      cin >> val;
      prerequisites[i] |= (1 << val);
    }
  }

  for (int i = 0; i < M; ++i)
  {
    int C;
    cin >> C;
    for (int j = 0; j < C; ++j)
    {
      int val;
      cin >> val;
      classes[i] |= (1 << val);
    }
  }
}

int bitCount(int value)
{
  int ret = 0;
  int target = value;
  while (target > 0)
  {
    if (target & 1)
    {
      ret++;
    }
    target >>= 1;
  }
  return ret;
}

int graduate(int sememster, int taken)
{
  if (bitCount(taken) >= K)
    return 0;

  if (sememster == M)
    return INF;

  int &ret = caches[sememster][taken];
  if (ret != -1)
    return ret;
  ret = INF;

  int canTake = (classes[sememster] & ~taken);

  for (int i = 0; i < N; ++i)
  {
    // Prerequesite이 충족?
    if ((canTake & (1 << i)) && ((taken & prerequisites[i]) != prerequisites[i]))
    {
      canTake &= ~(1 << i);
    }
  }

  for (int take = canTake; take > 0; take = ((take - 1) & canTake))
  {
    if (bitCount(take) > L)
      continue;

    ret = min(ret, graduate(sememster + 1, take | taken) + 1);
  }

  ret = min(ret, graduate(sememster + 1, taken));
  return ret;
}

int main(void)
{
  cin.sync_with_stdio(false);

  // freopen("./source.txt", "r", stdin);

  cin >> C;

  while (C--)
  {
    updateInput();

    int ret = graduate(0, 0);

    if (ret == INF)
    {
      cout << "IMPOSSIBLE" << endl;
    }
    else
    {
      cout << ret << endl;
    }
  }
}