#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool visited[999999] = {false};
int check = 1;
int color[99999]={-1};
int parent[10000];

pair<int,pair<int,int>> result[99999];

int find(int i)
{
  if(parent[i] == -1)
  return i;

  return find(parent[i]);
}

int unionSet(int x, int y)
{
  int xset = find(x);
  int yset = find(y);

  parent[xset] = yset;
  return 1;
}

int kruskalMST(vector<pair<int,pair<int,int>>> graph,int v)
{
  vector<pair<int,pair<int,int>>>:: iterator it;
  int e=0;

  memset(parent, -1, sizeof(parent));

  for(it=graph.begin(); it!=graph.end(); it++)
  {
    if(e> v-1)
    break;

    int x = find(it->second.first);
    int y = find(it->second.second);

    if(x != y)
    {
      result[e++] = make_pair(it->first,make_pair(it->second.first,it->second.second));
      unionSet(x,y);
    }
  }

  return 1;
}

int main()
{
  int i,wt,a,b;
  int u,v,e;
  cin>>v>>e;

  vector<pair<int,pair<int,int>>>::iterator vit;
  vector<pair<int,pair<int,int>>> graph;

  for(i=0;i<e;i++)
  {
    cin>>a>>b>>wt;
    graph.push_back(make_pair(wt,make_pair(a,b)));
  }

  sort(graph.begin(),graph.end());

  kruskalMST(graph,v);

  int sum = 0;
  for(i=0;i<v-1;i++)
  {
   sum = sum + result[i].first;
  }

cout<<sum;
  return 0;
}
