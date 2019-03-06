#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getxor(int a, int b)
{
  return (a | b) & (~a | ~b);
}

int main()
{
  int x, y, n, q;
  cin >> n >> q;
  vector<int> seq[n];

  int t;
  int lastAnswer = 0;
  for (int i = 0; i < q; i++)
  {
    cin >> t >> x >> y;

    int val = getxor(x, lastAnswer);

    if (t == 1)
    {
      int ind = val % n;
      seq[ind].push_back(y);
    }
    else if (t == 2)
    {
      int ind = val % n;
      lastAnswer = seq[ind][y % seq[ind].size()];
      cout << lastAnswer << endl;
    }
  }

  return 0;
}
