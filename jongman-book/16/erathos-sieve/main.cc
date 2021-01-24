#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, K;
  vector<bool> deleted(1001, false);

  cin >> N >> K;

  int counter = 0;
  int deletedValue = 2;
  for (int i = 2; i <= N; ++i)
  {
    if (!deleted[i])
    {
      // Delete all
      for (int j = 1; i * j <= N; ++j)
      {
        deletedValue = i * j;
        if (!deleted[deletedValue])
        {
          deleted[deletedValue] = true;
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