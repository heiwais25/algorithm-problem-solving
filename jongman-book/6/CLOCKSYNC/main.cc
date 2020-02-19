#include <iostream>
#define NUM_CLOCK 16
#define NUM_SWITCH 10
#define MAX_SWITCH_CLICK 4
#define MAX_VAL 987654321
using namespace std;

int clockValue[NUM_CLOCK];
int switchCount[NUM_SWITCH];
int switchRelation[NUM_SWITCH][NUM_CLOCK] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
};

void getClock()
{
    for (int i = 0; i < NUM_CLOCK; ++i)
    {
        int val;
        cin >> val;
        clockValue[i] = val;
    }

    for (int i = 0; i < NUM_SWITCH; ++i)
    {
        switchCount[i] = 0;
    }
}

bool isSolution()
{
    bool ret = true;
    for (int i = 0; i < NUM_CLOCK; ++i)
    {
        if (clockValue[i] != 12)
        {
            ret = false;
        }
    }
    return ret;
}

void applySwitch(int currentSwitch)
{
    for (int i = 0; i < NUM_CLOCK; ++i)
    {
        if (switchRelation[currentSwitch][i])
        {
            clockValue[i] += 3;
            if (clockValue[i] == 15)
            {
                clockValue[i] = 3;
            }
        }
    }
}

int clickSwitch(int currentSwitch)
{
    if (currentSwitch == NUM_SWITCH)
    {
        return isSolution() ? 0 : MAX_VAL;
    }

    int ret = MAX_VAL;
    for (int i = 0; i < 4; ++i)
    {
        ret = min(i + clickSwitch(currentSwitch + 1), ret);
        applySwitch(currentSwitch);
    }
    return ret;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    while (N--)
    {
        getClock();
        int count = clickSwitch(0);
        int ret = count == MAX_VAL ? -1 : count;
        cout << ret << endl;
    }
}