# include <stdio.h>
# include <math.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,i,min,max,min_count = 0,max_count= 0,va;

  cin>>n;

  for(i = 0; i<n; i++)
  {
    cin>>va;

    if(i==0)
    {
      min = va;
      max = va;
    }

    if(va > max)
    {
      ++max_count;
      max = va;
    }

    if(va < min)
    {
      ++min_count;
      min = va;
    }
  }

cout<<max_count<<" "<<min_count;

  return 0;
}
