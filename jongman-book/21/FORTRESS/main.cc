#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> x, y, r;

int square(int x) { return x * x; }

int squareDist(int i, int j) { return square(x[i] - x[j]) + square(y[i] - y[j]); }

// i enclose j
bool enclose(int i, int j)
{
  return r[i] > r[j] && squareDist(i, j) < square(r[i] - r[j]);
}

// Is j is child of i
bool isChild(int parent, int childCand)
{
  if (!enclose(parent, childCand))
    return false;
  // 전체를 돌면서 사이에 아무 원도 있으면 안된다.
  for (int i = 0; i < N; ++i)
  {
    if (i != parent && i != childCand && enclose(parent, i) && enclose(i, childCand))
    {
      return false;
    }
  }

  return true;
}

struct TreeNode
{
  vector<TreeNode *> children;
};

TreeNode *getTree(int root)
{
  TreeNode *rootNode = new TreeNode();
  for (int i = 0; i < N; ++i)
  {
    if (isChild(root, i))
    {
      rootNode->children.push_back(getTree(i));
    }
  }

  return rootNode;
}

int longest;

int getLongestPath(TreeNode *rootNode)
{
  vector<int> heights;
  for (int i = 0; i < rootNode->children.size(); ++i)
    heights.push_back(getLongestPath(rootNode->children[i]));

  if (heights.size() == 0)
  {
    return 0;
  }

  sort(heights.begin(), heights.end());

  if (heights.size() >= 2)
  {
    longest = max(longest, heights[heights.size() - 1] + heights[heights.size() - 2] + 2);
  }

  return heights.back() + 1;
}

int solve()
{
  longest = 0;

  TreeNode *root = getTree(0);

  return max(longest, getLongestPath(root));
}

int main(void)
{
  cin.sync_with_stdio(false);
  // freopen("./source.txt", "r", stdin);

  int C;
  cin >> C;
  while (C--)
  {
    cin >> N;
    vector<int> newX, newY, newR;
    for (int i = 0; i < N; i++)
    {
      int curX, curY, curR;
      cin >> curX >> curY >> curR;
      newX.push_back(curX);
      newY.push_back(curY);
      newR.push_back(curR);
    }
    x = newX;
    y = newY;
    r = newR;
    cout << solve() << endl;
  }
}