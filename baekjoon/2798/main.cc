#include <iostream>
#include <vector>
#define MAX_SELECTED_COUNT 3
using namespace std;

int N, M;

int solution(vector<int> &card, int lastSelected, int selectedCount, int sum)
{
    // base
    if (selectedCount == MAX_SELECTED_COUNT)
    {
        return sum;
    }

    int ret = 0;
    for (int cur = lastSelected + 1;
         cur < card.size() - (MAX_SELECTED_COUNT - selectedCount - 1);
         ++cur)
    {
        if (sum + card[cur] <= M)
        {
            ret = max(ret, solution(card, cur, selectedCount + 1, sum + card[cur]));
        }
    }
    return ret;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin >> N >> M;
    vector<int> card(N);

    for (int i = 0; i < N; ++i)
    {
        int val;
        cin >> val;
        card[i] = val;
    }

    cout << solution(card, -1, 0, 0) << endl;
}