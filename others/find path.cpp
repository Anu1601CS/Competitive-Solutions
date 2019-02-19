#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int check(vector<int> vec[], vector<bool> visited[], int n, int m)
{
    stack<pair<int, int>> s;
    bool che = false;

    s.push(make_pair(0, 0));

    while (!s.empty())
    {
        auto i = s.top().first;
        auto j = s.top().second;

        s.pop();

        if (vec[i][j] == 9)
        {
            che = true;
            break;
        }

        if (vec[i][j] == 0)
            break;

        if (!visited[i][j])
            visited[i][j] = true;

        if (i - 1 >= 0 && vec[i - 1][j] != 0 && !visited[i - 1][j])
            s.push(make_pair(i - 1, j));

        if (i + 1 < n && vec[i + 1][j] != 0 && !visited[i + 1][j])
            s.push(make_pair(i + 1, j));

        if (j - 1 >= 0 && vec[i][j - 1] != 0 && !visited[i][j - 1])
            s.push(make_pair(i, j - 1));

        if (j + 1 < m && vec[i][j + 1] != 0 && !visited[i][j + 1])
            s.push(make_pair(i, j + 1));
    }

    return che;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;

    vector<bool> visited[n];
    vector<int> vec[n];

    for (int i = 0; i < n; i++)
    {
        visited[i].assign(m, false);

        for (int j = 0; j < m; j++)
        {
            cin >> a;
            vec[i].push_back(a);
        }
    }

    if (check(vec, visited, n, m))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
