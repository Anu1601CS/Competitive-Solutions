// A simple representation of graph using STL
#include<bits/stdc++.h>
using namespace std;

int check = 0;
// A utility function to add an edge in an
// undirected graph.
void add(vector<pair<int,int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(v, wt));
}

void DFS_R(int u, int v, bool visited[], vector<pair<int,int>> adj[])
{
   visited[v] = true;

   vector<pair<int,int>>::iterator i;

   for(i = adj[v].begin(); i != adj[v].end(); i++)
   {
     if(!visited[i->first])
     {
       DFS_R(v, i->first, visited, adj);
     }
     else if(v != u)
     {
       check = 1;
       return;
     }
   }

}

// Driver code
int main()
{
    int V;
    int a,b,wt;

    cin>>V;
    vector<pair<int,int>> adj[V];

    for(int i = 0;i<V;i++)
    {
      cin>>a>>b;

      add(adj,a,b,0);
    }

    cout<<"\nDFS using recursion => ";

    bool visited[4] = {false};

    for(int i=0; i<V;i++)
    {
      if(!visited[i])
      {
        DFS_R(0,i, visited, adj);
      }
    }

    if(check)
    {
      cout<<"Cyclic";

    } else
    {
      cout<<" Not Cyclic";
    }

    return 0;
}
