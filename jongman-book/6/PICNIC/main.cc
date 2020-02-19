#include <iostream>
#include <vector>
#define MAX_NUM_STUDENTS 10
using namespace std;

int numStudents = 0;
bool isFriend[MAX_NUM_STUDENTS][MAX_NUM_STUDENTS];

void init()
{
    for (int i = 0; i < MAX_NUM_STUDENTS; ++i)
    {
        for (int j = 0; j < MAX_NUM_STUDENTS; ++j)
        {
            isFriend[i][j] = false;
        }
    }
}

int countCombination(vector<bool> &withPair)
{
    int current = -1;
    for (int i = 0; i < withPair.size(); ++i)
    {
        if (!withPair[i])
        {
            current = i;
            break;
        }
    }

    if (current == -1)
    {
        return 1;
    }

    int count = 0;

    for (int i = 0; i < MAX_NUM_STUDENTS; ++i)
    {
        if (isFriend[current][i] && !withPair[i])
        {
            withPair[i] = withPair[current] = true;
            count += countCombination(withPair);
            withPair[i] = withPair[current] = false;
        }
    }
    return count;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    while (N--)
    {
        init();
        int m;
        cin >> numStudents >> m;
        vector<bool> withPair(numStudents, 0);
        while (m--)
        {
            int first, second;
            cin >> first >> second;
            isFriend[first][second] = true;
            isFriend[second][first] = true;
        }
        cout << countCombination(withPair) << endl;
    }
}