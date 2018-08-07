#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  cin>>n>>s;

  int d=0,lo=0,up=0,sc=0;

  for(int i=0;i<s.length();i++)
  {
    if(s[i] >= 48 && s[i] <= 57)
      d=1;

    if(s[i] >= 65 && s[i] <= 90)
      up=1;

    if(s[i] >= 97 && s[i] <= 122)
      lo=1;

    if(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '^'
      || s[i] == '&' || s[i] == '*' || s[i] == '(' || s[i] == ')' || s[i] == '-' || s[i] == '+' || s[i] == '$')
      sc=1;

  }

  int total = d+up+lo+sc;
  total = 4 - total;

  if(n >= 6 || n+total >= 6)
  cout<<total;
  else
  cout<<6-n;
  return 0;
}
