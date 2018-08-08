#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool visited[999999] = {false};
int check = 1;
int color[99999]={-1};

pair<int,pair<int,int>> result[99999];

int find(int parent[], int i)
{
  if(parent[i] == -1)
  return i;

  return find(parent, parent[i]);
}

int unionSet(int parent[], int x, int y)
{
  int xset = find(parent,x);
  int yset = find(parent,y);
  parent[xset] = yset;
}

int kruskalMST(vector<pair<int,pair<int,int>>> graph,int v)
{
  vector<pair<int,pair<int,int>>>:: iterator it;
  int e=0;

  int parent[1000];

  for(it=graph.begin(); it!=graph.end(); it++)
  {
    if(e> v-1)
    break;

    memset(parent, -1, sizeof(parent));

    int x = find(parent, it->second.first);
    int y = find(parent, it->second.second);

    if(x != y)
    {
      result[e++] = make_pair(it->first,make_pair(it->second.first,it->second.second));
      unionSet(parent,x,y);
    }
  }

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

  for(i=0;i<=v-1;i++)
  {
   cout<<result[i].second.first<<"--"<<result[i].second.second<<"=>"<<result[i].first<<endl;
  }

  return 0;
}
