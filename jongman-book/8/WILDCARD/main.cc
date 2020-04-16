#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_SIZE 100

using namespace std;

int cache[MAX_SIZE + 1][MAX_SIZE + 1];

int match(const string &pattern, const string &target, int p, int t)
{

    int &ret = cache[p][t];
    if (ret != -1)
        return ret;

    int ps = pattern.size(), ts = target.size();

    if (p < ps && t < ts &&
        (pattern[p] == '?' || pattern[p] == target[t]))
    {
        return ret = match(pattern, target, p + 1, t + 1);
    }

    if (p == ps)
    {
        return ret = (t == ts);
    }

    if (pattern[p] == '*')
    {
        if (match(pattern, target, p + 1, t) || (t < ts && match(pattern, target, p, t + 1)))
        {
            return ret = 1;
        }
    }
    return ret = 0;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int C;
    cin >> C;
    while (C--)
    {
        string pattern;
        cin >> pattern;

        int N;
        cin >> N;

        vector<string> targets(N);
        for (auto it = targets.begin(); it != targets.end(); ++it)
        {
            cin >> *it;
        }

        vector<string> solutions;
        for (auto target : targets)
        {
            memset(cache, -1, sizeof(cache));
            if (match(pattern, target, 0, 0))
            {
                solutions.push_back(target);
            }
        }

        sort(solutions.begin(), solutions.end());
        for (auto solution : solutions)
        {
            cout << solution << endl;
        }
    }
}