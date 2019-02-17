
#include <bits/stdc++.h>
using namespace std;
#define N 4

int V;
vector<int> adj[N];

void addEdge(int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

bool BFS(int s, int d)
{
    if (s == d)
        return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (*i == d)
                return true;

            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}

bool isSafe(int i, int j, int M[][N])
{
    if ((i < 0 || i >= N) ||
        (j < 0 || j >= N) || M[i][j] == 0)
        return false;
    return true;
}

bool findPath(int M[][N])
{
    int s, d;
    int V = N * N + 2;

    int k = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (M[i][j] != 0)
            {
                if (isSafe(i, j + 1, M))
                    addEdge(k, k + 1);
                if (isSafe(i, j - 1, M))
                    addEdge(k, k - 1);
                if (j < N - 1 && isSafe(i + 1, j, M))
                    addEdge(k, k + N);
                if (i > 0 && isSafe(i - 1, j, M))
                    addEdge(k, k - N);
            }

            if (M[i][j] == 1)
                s = k;

            if (M[i][j] == 2)
                d = k;
            k++;
        }
    }

    return BFS(s, d);
}

int main()
{
    int M[N][N] = {
        {1, 0, 0, 0},
        {3, 0, 3, 3},
        {2, 3, 3, 3},
        {0, 3, 3, 3}};

    (findPath(M) == true) ? cout << "Yes" : cout << "No" << endl;

    return 0;
}
