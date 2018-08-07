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

int dfs(vector<pair<int,int>> vec[],int start, int color_id)
{
  if(!check)
  return 0;

  visited[start] = true;

  color[start] = color_id;

  vector<pair<int,int>>::iterator i;

  for(i= vec[start].begin(); i!= vec[start].end(); i++)
  {
    if(color[i->first] == -1)
    {
      dfs(vec, i->first, 1 - color_id);
    }
    else if(color[i->first] == color_id)
    {
      check = 0;
      return 0;
    }
  }

  st.push(start);
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

  for(i=0; i<v; i++)
  {
    if(!visited[i])
    {
      dfs(vec,0,0);
    }
  }

  if(check)
  cout<<"YES";
  else
  cout<<"NO";

  return 0;
}
