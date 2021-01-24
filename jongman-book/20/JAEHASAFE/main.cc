#include <iostream>
#include <vector>

using namespace std;

vector<int> getPartialMatchTable(const string &N)
{
  int n = N.size();
  vector<int> pi(n, 0);
  int begin = 1, matched = 0;

  while (begin + matched < n)
  {
    if (N[begin + matched] == N[matched])
    {
      ++matched;
      pi[begin + matched - 1] = matched;
    }
    else
    {
      if (matched == 0)
      {
        ++begin;
      }
      else
      {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return pi;
}

vector<int> kmpSearch(const string &H, const string &N)
{
  int m = H.size(), n = N.size();
  vector<int> pi = getPartialMatchTable(N);
  vector<int> ret;
  int matched = 0;
  for (int i = 0; i < m; ++i)
  {
    while (matched > 0 && H[i] != N[matched])
    {
      matched = pi[matched - 1];
    }

    if (H[i] == N[matched])
    {
      ++matched;
      if (matched == n)
      {
        ret.push_back(i - n + 1);
        matched = pi[n - 1];
      }
    }
  }

  return ret;
}

int shifts(const string &original, const string &target)
{
  return kmpSearch(original + original, target)[0];
}

int main(void)
{
  cin.sync_with_stdio(false);
  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {
    int N;
    string original, target;
    int cnt = 0;
    cin >> N;

    cin >> target;
    for (int i = 0; i < N; ++i)
    {
      string original(target);
      cin >> target;
      if (i % 2 == 1)
      {
        cnt += shifts(original, target);
      }
      else
      {
        cnt += shifts(target, original);
      }
    }

    cout << cnt << endl;
  }
}