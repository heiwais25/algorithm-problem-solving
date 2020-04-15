#include <iostream>
#include <vector>

using namespace std;

vector<int> normalize(vector<int> &a)
{
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (a[i] < 0)
        {
            int borrow = (abs(a[i]) + 9) / 10;
            a[i + 1] -= borrow;
            a[i] += borrow * 10;
        }
        else
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
    }

    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> ret(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            ret[i + j] += a[i] * b[j];
        }
    }

    // normalize(ret);
    return ret;
}

// a -= b
void subFrom(vector<int> &a, const vector<int> &b)
{
    for (int i = 0; i < b.size(); ++i)
    {
        a[i] -= b[i];
    }
    // normalize(a);
}

// a += b * 10^k
void addTo(vector<int> &a, const vector<int> &b, int k)
{
    if (a.size() < b.size() + k)
    {
        a.resize(b.size() + k + 1);
    }
    for (int i = 0; i < b.size(); ++i)
    {
        a[i + k] += b[i];
    }
    // normalize(a);
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
    int an = a.size(), bn = b.size();
    if (an < bn)
    {
        return karatsuba(b, a);
    }
    if (an == 0 || bn == 0)
    {
        return vector<int>();
    }
    if (an < 100)
    {
        return multiply(a, b);
    }

    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(half, bn));
    vector<int> b1(b.begin() + min<int>(half, bn), b.end());

    vector<int> c0 = karatsuba(a0, b0);
    vector<int> c2 = karatsuba(a1, b1);

    addTo(a1, a0, 0);
    addTo(b1, b0, 0);

    vector<int> c1 = karatsuba(a1, b1);
    subFrom(c1, c0);
    subFrom(c1, c2);

    vector<int> ret;
    addTo(ret, c0, 0);
    addTo(ret, c1, half);
    addTo(ret, c2, half + half);
    return ret;
}

int solve(const vector<int> &members, const vector<int> &fans)
{
    vector<int> ret = karatsuba(members, fans);
    int cnt = 0;
    for (int i = members.size() - 1; i < fans.size(); ++i)
    {
        if (ret[i] == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

vector<int> parse(string a, bool reverse)
{
    vector<int> ret;
    if (reverse)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            ret.push_back(a[i] == 'F' ? 0 : 1);
        }
    }
    else
    {
        for (int i = a.size() - 1; i >= 0; --i)
        {
            ret.push_back(a[i] == 'F' ? 0 : 1);
        }
    }
    return ret;
}

int main(void)
{
    cin.sync_with_stdio(false);
    // freopen("./input.txt", "r", stdin);

    int N;
    cin >> N;

    while (N--)
    {
        string line;
        cin >> line;
        vector<int> a = parse(line, false);
        cin >> line;
        vector<int> b = parse(line, true);
        cout << solve(a, b) << endl;
    }
}