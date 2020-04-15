#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxRect(vector<int> &height, int left, int right)
{
    if (left == right)
    {
        return height[left];
    }

    int mid = (left + right) / 2;
    int ret = max(getMaxRect(height, left, mid), getMaxRect(height, mid + 1, right));

    // Calculate the maximum size which is passing the center line
    int lo = mid, hi = mid + 1;
    int curHeight = min(height[lo], height[hi]);
    ret = max(ret, 2 * curHeight);

    while (left < lo || hi < right)
    {
        if (hi < right && (lo == left || height[lo - 1] < height[hi + 1]))
        {
            hi++;
            curHeight = min(curHeight, height[hi]);
        }
        else
        {
            lo--;
            curHeight = min(curHeight, height[lo]);
        }
        ret = max(ret, curHeight * (hi - lo + 1));
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
        vector<int> height;
        int count;
        cin >> count;
        while (count--)
        {
            int val;
            cin >> val;
            height.push_back(val);
        }

        cout << getMaxRect(height, 0, height.size() - 1) << endl;
    }
}
