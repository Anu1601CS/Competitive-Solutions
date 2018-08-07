#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool visited[999999] = {false};
int check = 1;
int color[99999]={-1};

vector<pair<int,int>> newVec[1000];

stack<int> st;

int getTranspose(vector<pair<int,int>> vec[], int size)
{
  vector<pair<int,int>>::iterator j;

  int i;
  for(i=0; i<size; i++)
    {
      for(j= vec[i].begin(); j!= vec[i].end();j++)
      {
        newVec[j->first].push_back(make_pair(i,0));
      }
    }
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
  }

  cout<<"Strongly Connected component in directed graph"<<endl;
  int count = 1;
  for(i=0; i<v; i++)
  {
    if(!visited[i])
    {
      dfs(vec,i);
    }
  }

  cout<<endl;

  getTranspose(vec,v);

  for(i=0; i<v; i++)
  {
    visited[i] = false;
  }

  while (!st.empty())
  {
    int gh = st.top();
    st.pop();

    if(!visited[gh])
    {
      cout<<"\n"<<count<<"-> ";
      dfs(newVec,gh);
      ++count;
    }
  }


  return 0;
}
