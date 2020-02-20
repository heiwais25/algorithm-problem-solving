#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    // freopen("./input.txt", "r", stdin);

    int N;
    cin >> N;
    vector<int> length, weight, rank;

    while (N--)
    {
        int l, w;

        cin >> l >> w;
        length.push_back(l);
        weight.push_back(w);
    }

    for (int i = 0; i < length.size(); i++)
    {
        int curRank = 1;
        for (int j = 0; j < length.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (length[i] < length[j] && weight[i] < weight[j])
            {
                curRank++;
            }
        }
        cout << curRank << " ";
    }
    cout << endl;
}