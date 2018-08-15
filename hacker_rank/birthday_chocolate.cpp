#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,i,j,d,m,count = 0,b = 0,total = 0;
  cin>>n;

  int s[n];

  for(i=0;i<n;i++)
    cin>>s[i];

  cin>>d>>m;

  for(i=0;i<n;i++)
  {
    b = 0;
    total = s[i];

    for(j=1; j<m; j++)
      total = total + s[i+j];

    if(total == d)
      ++count;
  }

  cout<<count;

  return 0;
}
