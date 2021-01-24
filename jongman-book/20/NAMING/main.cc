#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getPartialMatch(const string &N)
{
  int m = N.size();
  vector<int> pi(N.size(), 0);

  int begin = 1, matched = 0;

  while (begin + matched < m)
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
        begin++;
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

vector<int> solve(const string &N)
{
  vector<int> pi = getPartialMatch(N);
  vector<int> ret;
  int n = N.size();

  while (n > 0)
  {
    ret.push_back(n);
    n = pi[n - 1];
  }

  sort(ret.begin(), ret.end());
  return ret;
}

int main(void)
{
  cin.sync_with_stdio(false);
  // freopen("source.txt", "r", stdin);

  string first, second;
  cin >> first;
  cin >> second;

  string merged = first + second;
  vector<int> ret = solve(merged);

  int length = ret.size();
  for (int i = 0; i < length; ++i)
  {
    cout << ret[i];
    if (i != length - 1)
    {
      cout << " ";
    }
  }
  cout << endl;
}