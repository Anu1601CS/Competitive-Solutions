#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v;
  vector<int>::iterator vit;

  int n,m,i,j,count=0,flag = 0;

  cin>>n>>m;

  array<int, 10> a;
  array<int, 10> b;

  for(i = 0;i<n; i++)
  {
    cin>>a[i];
  }

  for(i = 0; i<m; i++)
  {
    cin>>b[i];
  }

  int low = a[n-1],
    high = b[0];

  for(i = low; i <= high; i++)
  {
    flag = 0;
    for(j = 0; j<n; j++)
    {
      if(i % a[j] == 0)
      {
        ++flag;
      }
    }

    if(flag == n)
    {
      v.push_back(i);
    }
  }


  for(vit = v.begin(); vit != v.end(); vit++)
  {
    flag = 0;
    for(i=0; i<m; i++)
    {
      if(b[i] % *vit == 0)
      {
        ++flag;
      }
    }
    if(flag == m)
    {
      ++count;
    }
  }
  cout<<count;

  return 0;
}
