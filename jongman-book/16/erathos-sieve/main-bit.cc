#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<char> deleted((1000 + 7) / 8);

bool isDeleted(int k)
{
  return deleted[k >> 3] & (1 << (k & 7));
}

void setDeleted(int k)
{
  deleted[k >> 3] |= 1 << (k & 7);
}

int main()
{
  cin >> N >> K;

  int counter = 0;
  int deletedValue = 2;
  for (int i = 2; i <= N; ++i)
  {
    if (!isDeleted(i))
    {
      // Delete all
      for (int j = 1; i * j <= N; ++j)
      {
        deletedValue = i * j;
        if (!isDeleted(deletedValue))
        {
          setDeleted(deletedValue);
          counter++;

          if (counter == K)
          {
            break;
          }
        }
      }
    }

    if (counter == K)
    {
      break;
    }
  }

  cout << deletedValue << endl;
}