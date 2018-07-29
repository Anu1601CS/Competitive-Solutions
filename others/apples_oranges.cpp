#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int apples,oranges,s,t,a,b,m,n,num_a = 0, num_o = 0,val;

  cin>>s>>t;
  cin>>a>>b;
  cin>>m>>n;

  for (int i=0;i<m;i++)
  {
    cin>>apples;

    val = apples + a;
    if (val >= s && val <= t)
    {
      ++num_a;
    }
  }

  for (int i=0;i<n;i++)
  {
    cin>>oranges;

    val = oranges + b;
    if (val >= s && val <= t)
    {
      ++num_o;
    }
  }

  cout<<num_a<<endl<<num_o;
  return 0;
}
