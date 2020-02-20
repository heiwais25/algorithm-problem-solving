#include <iostream>
using namespace std;

bool isFinalNumber(int num)
{
    bool isFinal = false;
    while (num)
    {
        int firstWindow = num % 1000;
        int secondWindow = (num % 10000) / 10;
        int thirdWindow = (num % 100000) / 100;
        if (firstWindow == 666 || secondWindow == 666 || thirdWindow == 666)
        {
            isFinal = true;
            break;
        }
        num /= 1000;
    }
    return isFinal;
}

int main(void)
{
    // freopen("./input.txt", "r", stdin);
    int N;
    cin >> N;

    int finalCount = 0;
    int cur = 666;
    while (1)
    {
        if (isFinalNumber(cur))
        {
            finalCount++;
        }
        if (finalCount == N)
        {
            cout << cur << endl;
            break;
        }
        cur++;
    }
}
