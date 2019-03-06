#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<bool> vis[55];

void dfsFindX(pair<int, int> s, vector<string> graph, int n, int m)
{
  stack<pair<int, int>> st;

  st.push(s);

  while (!st.empty())
  {
    auto u = st.top();

    int i = u.first;
    int j = u.second;

    st.pop();

    vis[i][j] = true;

    // Bottom
    if (i + 1 <= n - 1 && !vis[i + 1][j] && graph[i + 1][j] == 'X')
      st.push(make_pair(i + 1, j));

    // Top
    if (i - 1 >= 0 && !vis[i - 1][j] && graph[i - 1][j] == 'X')
      st.push(make_pair(i - 1, j));

    // Right
    if (j + 1 <= m - 1 && !vis[i][j + 1] && graph[i][j + 1] == 'X')
      st.push(make_pair(i, j + 1));

    // Left
    if (j - 1 >= 0 && !vis[i][j - 1] && graph[i][j - 1] == 'X')
      st.push(make_pair(i, j - 1));
  }
}

int main()
{
  int t;

  cin >> t;

  while (t--)
  {
    int n, m;
    cin >> n >> m;

    vector<string> graph;
    string s;

    for (int i = 0; i < n; i++)
    {
      vis[i].assign(m + 1, false);
      cin >> s;
      graph.push_back(s);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!vis[i][j])
        {
          if (graph[i][j] == 'O')
          {
            vis[i][j] = true;
            continue;
          }

          ++ans;
          dfsFindX(make_pair(i, j), graph, n, m);
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
