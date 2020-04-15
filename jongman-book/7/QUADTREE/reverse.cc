#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse(string::iterator &it)
{
    string ret = "";
    char head = *(it++);
    if (head == 'w' || head == 'b')
    {
        ret += head;
        return ret;
    }

    string first = reverse(it);
    string second = reverse(it);
    string third = reverse(it);
    string fourth = reverse(it);

    return "x" + third + fourth + first + second;
}

int main(void)
{
    cin.sync_with_stdio(false);
    // freopen("./input.txt", "r", stdin);

    int N;
    cin >> N;
    while (N--)
    {
        string source;
        cin >> source;

        // Reverse
        string::iterator it = source.begin();
        cout << reverse(it) << endl;
    }
}