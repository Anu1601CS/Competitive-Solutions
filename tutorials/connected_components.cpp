#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool visited[999999] = {false};
int check = 1;
int color[99999]={-1};

stack<int> st;

void addEdge(vector<pair<int,int>> vec[], int a,int b,int wt)
{
  vec[a].push_back(make_pair(b,wt));
  vec[b].push_back(make_pair(a,wt));
}

int dfs(vector<pair<int,int>> vec[], int start)
{

  visited[start] = true;

  cout<<start<<" ";

  vector<pair<int,int>>::iterator i;

  for(i= vec[start].begin(); i!= vec[start].end(); i++)
  {
    if(!visited[i->first])
    {
      dfs(vec, i->first);
    }
  }

  return 0;
}

int main()
{
  int i,wt,a,b;
  int u,v,e;
  cin>>v>>e;

  vector<pair<int,int>>::iterator vit;
  vector<pair<int,int>> vec[v];

  for(i=0; i<e; i++)
  {
    cin>>a>>b;

    vec[a].push_back(make_pair(b,0));
    vec[b].push_back(make_pair(a,0));
  }

  cout<<"Connected component in directed graph"<<endl;
  int count = 1;
  for(i=0; i<v; i++)
  {
    if(!visited[i])
    {
      cout<<count<<"-> ";
        ++count;
      dfs(vec,i);
      cout<<endl;
    }
  }

  return 0;
}
