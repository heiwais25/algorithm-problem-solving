#include <iostream>
#include <vector>
#include <algorithm>

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

int solve(const string &H)
{
  string target(H);
  reverse(target.begin(), target.end());
  int m = H.size();

  vector<int> pi = getPartialMatchTable(target);
  int begin = 0, matched = 0;

  while (begin + matched < m)
  {
    if (H[begin + matched] == target[matched])
    {
      ++matched;
      if (begin + matched == m)
      {
        break;
      }
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

  return m + begin;
}

int main(void)
{
  cin.sync_with_stdio(false);
  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {
    string line;
    cin >> line;

    cout << solve(line) << endl;
  }
}