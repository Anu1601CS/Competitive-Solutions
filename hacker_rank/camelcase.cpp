#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int count = 1;
  string s;
  cin>>s;

  for(int i=0;i<s.length();i++)
  {
    if((int) s[i] >= 65 && (int) s[i] <= 90)
    {
      ++count;
    }
  }

  cout<<count;
  return 0;
}
