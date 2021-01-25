#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int> &source, int begin, int end)
{
  return vector<int>(source.begin() + begin, source.begin() + end);
}

void printPostOrder(const vector<int> &preOrder, const vector<int> &inOrder)
{
  // Find root
  if (preOrder.size() == 0)
    return;

  int root = preOrder[0];
  // find the root order in the inOrder
  // end index of L
  int L = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin();

  // Slice preOrder: 1 ~ 1 + L, 1+L ~ end
  // Slice inOrder: 0 ~ L, L+1 ~ end

  // 0, 1, 2, L
  printPostOrder(slice(preOrder, 1, L + 1), slice(inOrder, 0, L));
  printPostOrder(slice(preOrder, L + 1, preOrder.size()), slice(inOrder, L + 1, inOrder.size()));

  cout << root << " ";
}

int main(void)
{
  cin.sync_with_stdio(false);

  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {
    int N;
    cin >> N;
    vector<int> preOrder, inOrder;

    int val;
    for (int i = 0; i < N; ++i)
    {
      cin >> val;
      preOrder.push_back(val);
    }

    for (int i = 0; i < N; ++i)
    {
      cin >> val;
      inOrder.push_back(val);
    }

    printPostOrder(preOrder, inOrder);
    cout << endl;
  }
}