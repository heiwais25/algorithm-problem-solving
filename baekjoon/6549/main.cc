#include <iostream>
#include <vector>

using namespace std;

// Find the solution in [start, end] with h (maximum)
long long solve(const vector<long long> &h, int start, int end)
{
    long long ret = 0;
    if (start == end)
    {
        return h[start];
    }

    int half = (end + start) / 2;
    ret = max(solve(h, start, half), solve(h, half + 1, end));

    // Calculate
    int left = half;
    int right = half + 1;
    long long height = min(h[left], h[right]);
    ret = max(ret, height * 2);
    while (left > start || right < end)
    {
        if (left > start && (h[left - 1] >= h[right + 1] || right == end))
        {
            left--;
            height = min(h[left], height);
        }
        else
        {
            right++;
            height = min(h[right], height);
        }
        ret = max(ret, height * (right - left + 1));
    }

    return ret;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    while (true)
    {
        vector<long long> h;
        cin >> N;
        if (N == 0)
            break;

        while (N--)
        {
            long long val;
            cin >> val;
            h.push_back(val);
        }
        cout << solve(h, 0, h.size() - 1) << endl;
    }
}