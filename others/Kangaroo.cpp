#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int x1,v1,x2,v2,y;

  cin>>x1>>v1>>x2>>v2;

  if (x2 > x1 && v2 > v1)
  {
    cout<<"NO";
    return 0;
  }

  if (x1 > x2 && v1 > v2)
  {
    cout<<"NO";
    return 0;
  }

  if (v1 == v2 && x1!=x2)
  {
    cout<<"NO";
    return 0;
  }

  y = (x1-x2) / (v2-v1);

  if( (x1 + y*v1) == (x2+ y*v2) )
  {
    cout<<"YES";
    return 0;
  }

  cout<<"NO";
  return 0;
}
