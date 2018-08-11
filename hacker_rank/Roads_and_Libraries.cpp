#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SYNC ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;

long long int visited[100000];
long long int road;

long long int findCost(vector<long long int> vec[], long long int u)
{
  visited[u] = true;

  vector<long long int>::iterator it;

  for(it=vec[u].begin(); it!=vec[u].end(); it++)
  {
    if(!visited[*it])
    {
      ++road;
      findCost(vec,*it);
    }
  }
  return 0;
}

int main()
{
  SYNC

  long long int query;
  cin>>query;
  vector<long long int> result;

  while(query >0)
  {
    long long int i,wt,a,b;
    long long int u,v,n,m,count;

    long long int c_lib,c_road;
    cin>>v>>m>>c_lib>>c_road;

    vector<long long int>::iterator vit;
    vector<long long int> vec[100000];
    vector<pair<long long int,long long int>> vep;

    for(i=0; i<m; i++)
    {
      cin>>a>>b;

      vec[a].push_back(b);
      vec[b].push_back(a);
    }

    for(i=1;i<=v;i++)
    visited[i] = false;

    long long int etc = 0;

    for(i=1;i<=v;i++)
    {
      road = 0;
      count = 0;

      if(!visited[i])
      {
        ++count;
        findCost(vec,i);
        vep.push_back(make_pair(road, count));
      }
    }

    long long int total1 = 0, total2 =0;

    vector<pair<long long int,long long int>>::iterator vecp;

    for(vecp = vep.begin(); vecp!= vep.end(); vecp++)
    {
      total1 = total1 + vecp->first*c_road + vecp->second*c_lib;
    }

    total2 = v*c_lib;

    if(total1 < total2)
    result.push_back(total1);
    else
    result.push_back(total2);

    --query;
  }

  vector<long long int>::iterator vit2;
  for(vit2=result.begin(); vit2!=result.end(); vit2++)
  cout<<*vit2<<endl;

  return 0;
}
