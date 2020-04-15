#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> target;

void decode(string::iterator &it, int y, int x, int size)
{
    char head = *(it++);
    if (head == 'w' || head == 'b')
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                target[y + i][x + j] = head;
            }
        }
    }
    else
    {
        int half = size / 2;
        decode(it, y, x, half);
        decode(it, y, x + half, half);
        decode(it, y + half, x, half);
        decode(it, y + half, x + half, half);
    }
}

int getSize(string::iterator &it)
{
    char head = *(it++);
    if (head == 'w' || head == 'b')
    {
        return 1;
    }

    int size = max(getSize(it), getSize(it));
    size = max(size, getSize(it));
    size = max(size, getSize(it));
    return 2 * size;
}

int main(void)
{
    // Decode from quadtree value
    string source = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";

    // Calculate the size
    string::iterator it = source.begin();
    int size = getSize(it);
    for (int i = 0; i < size; ++i)
    {
        target.push_back(vector<char>(size));
    }

    it = source.begin();
    decode(it, 0, 0, size);

    for (int i = 0; i < target.size(); ++i)
    {
        for (int j = 0; j < target[i].size(); ++j)
        {
            cout << target[i][j];
        }
        cout << endl;
    }
}