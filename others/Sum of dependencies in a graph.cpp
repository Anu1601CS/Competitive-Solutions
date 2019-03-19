#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;

  cin >> t;

  while (t--)
  {
    int n, e;
    cin >> n >> e;

    vector<int> graph[n];

    int a, b;

    for (int i = 0; i < e; i++)
    {
      cin >> a >> b;
      graph[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = ans + graph[i].size();

    cout << ans << endl;
  }

  return 0;
}
