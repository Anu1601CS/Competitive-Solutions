// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void add(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void BSF(vector<int> adj[], int V, int s)
{
  bool visited[V] = {false};

  list<int> q;

  visited[s] = true;
  q.push_back(s);

  vector<int>::iterator i;

  while (!q.empty())
  {
    s = q.front();
    cout << s << " ";
    q.pop_front();

    for (i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        q.push_back(*i);
      }
    }
  }
}

// A utility function to print the adjacency list
// representation of graph
void DSF(vector<int> adj[], int V, int s)
{
  bool visited[V] = {false};

  stack<int> stack;

  stack.push(s);

  vector<int>::iterator i;

  while (!stack.empty())
  {
    s = stack.top();
    stack.pop();

    if (!visited[s])
    {
      cout << s << " ";
      visited[s] = true;
    }

    for (i = adj[s].begin(); i != adj[s].end(); ++i)
    {
      if (!visited[*i])
      {
        stack.push(*i);
      }
    }
  }
}

void DFS_R(int v, bool visited[], vector<int> adj[])
{
  visited[v] = true;
  cout << v << " ";

  vector<int>::iterator i;

  for (i = adj[v].begin(); i != adj[v].end(); i++)
  {
    if (!visited[*i])
      DFS_R(*i, visited, adj);
  }
}

// Driver code
int main()
{
  int V;
  int a, b;

  cin >> V;
  vector<int> adj[V];

  for (int i = 0; i < V; i++)
  {
    cin >> a >> b;

    add(adj, a, b);
  }

  cout << "BSF => ";
  BSF(adj, V, 0);
  cout << "\nDFS => ";
  DSF(adj, V, 0);

  cout << "\nDFS using recursion => ";

  bool visited[4] = {false};

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      cout << "u";
      DFS_R(i, visited, adj);
    }
  }

  return 0;
}
