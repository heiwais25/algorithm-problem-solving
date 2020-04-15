#include <iostream>
#include <vector>
#include <string>
#define MAX_SIZE 4

using namespace std;

string encode(char source[MAX_SIZE][MAX_SIZE], int y, int x, int size)
{
    string ret = "";
    if (size == 1)
    {
        ret += source[y][x];
        return ret;
    }

    int half = size / 2;
    ret = "x" +
          encode(source, y, x, half) +
          encode(source, y, x + half, half) +
          encode(source, y + half, x, half) +
          encode(source, y + half, x + half, half);

    if (ret.size() == 5)
    {
        if (ret[1] == ret[2] && ret[2] == ret[3] && ret[3] == ret[4])
        {
            if (ret[1] == 'w')
            {
                ret = 'w';
            }
            else
            {
                ret = 'b';
            }
        }
    }
    return ret;
}

int main(void)
{
    char source[MAX_SIZE][MAX_SIZE] = {
        {'b', 'b', 'b', 'b'},
        {'b', 'b', 'b', 'b'},
        {'b', 'b', 'b', 'b'},
        {'b', 'b', 'b', 'b'}};

    string target = encode(source, 0, 0, MAX_SIZE);
    cout << target << endl;
}