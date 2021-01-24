#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Comparator
{
  const vector<int> &group;
  int t;
  Comparator(const vector<int> &_group, int _t) : group(_group), t(_t)
  {
  }

  bool operator()(int a, int b)
  {
    if (group[a] != group[b])
      return group[a] < group[b];

    return group[a + t] < group[b + t];
  }
};

vector<int> getSuffixArray(const string &N)
{
  int n = N.size();
  vector<int> group(n + 1);
  vector<int> perm(n);

  for (int i = 0; i < n; ++i)
  {
    perm[i] = i;
    group[i] = N[i];
  }

  group[n] = -1;

  int t = 1;
  // => NlgN^2
  while (t < n) // lgN
  {
    Comparator comparator(group, t);
    sort(perm.begin(), perm.end(), comparator); // NlgN

    t *= 2;
    if (t >= n)
      break;

    vector<int> newGroup(n + 1);
    newGroup[perm[0]] = 0;
    newGroup[n] = -1;

    for (int i = 1; i < n; ++i)
    {
      if (comparator(perm[i - 1], perm[i]))
      {
        newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
      }
      else
      {
        newGroup[perm[i]] = newGroup[perm[i - 1]];
      }
    }

    group = newGroup;
  }

  return perm;
}

int commonPrefix(const string &s, int i, int j)
{
  int length = s.size(), k = 0;
  while (i + k < length && j + k < length && s[i + k] == s[j + k])
  {
    ++k;
  }

  return k;
}

int solve(const string &s, int k)
{
  vector<int> suffixArray = getSuffixArray(s);
  int l = suffixArray.size();
  int ret = -1;
  for (int i = 0; i + k <= l; ++i)
  {
    ret = max(ret, commonPrefix(s, suffixArray[i], suffixArray[i + k - 1]));
  }
  return ret;
}

// 부분 문자열
int main(void)
{
  cin.sync_with_stdio(false);

  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {
    int k;
    string s;
    cin >> k;
    cin >> s;

    cout << solve(s, k) << endl;
  }
}