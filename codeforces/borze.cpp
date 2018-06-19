Copy
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;

  char s1='.',s2='-';
  cin>>s;

  int i,l;
  l=s.size();

  int flag=1;
  i=0;

  while(i<l)
  {
    flag=1;
    if(s[i]==s1)
    {
      cout<<"0";
    }
    else
    if(s[i]==s2 && s[i+1]==s1)
    {
      cout<<"1";
      i=i+2;
      flag=0;
    }
    else
    if(s[i]==s2 && s[i+1]==s2)
    {
      cout<<"2";
      i=i+2;
      flag=0;
    }

    if(flag==1)
    i++;
  }
  return 0;
}
