#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
};

bool compare(Point &a, Point &b)
{
    return a.x < b.x;
}

bool compareByY(Point &a, Point &b)
{
    return a.y < b.y;
}

int dist(const Point &a, const Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int closestDistance(const vector<Point>::iterator it, int n)
{
    if (n == 2)
    {
        return dist(it[0], it[1]);
    }
    else if (n == 3)
    {
        return min({dist(it[0], it[1]), dist(it[1], it[2]), dist(it[2], it[0])});
    }

    int half = n / 2;
    int line = (it[half - 1].x + it[half].x) / 2;
    int d = min(closestDistance(it, half), closestDistance(it + half, n - half));

    vector<Point> center;
    center.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int t = line - it[i].x;
        if (t * t < d)
        {
            center.push_back(it[i]);
        }
    }

    sort(center.begin(), center.end(), compareByY);
    int centerSize = center.size();
    for (int i = 0; i < centerSize - 1; ++i)
    {
        for (int j = i + 1;
             j < centerSize && (center[j].y - center[i].y) * (center[j].y - center[i].y) < d;
             ++j)
        {
            d = min(d, dist(center[i], center[j]));
        }
    }

    // Center
    return d;
}

int main(void)
{
    freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point> points(N);
    for (auto it = points.begin(); it != points.end(); ++it)
    {
        cin >> it->x >> it->y;
    }

    sort(points.begin(), points.end(), compare);

    cout << closestDistance(points.begin(), N) << endl;
}