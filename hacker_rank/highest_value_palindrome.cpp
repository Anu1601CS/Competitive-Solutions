#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n,k,i,count = 0;
  long long int ch = 0;
  cin>>n>>k;

  string s;
  cin>>s;

  //s.resize();
  if(s.length() == 1 && k >= 1)
  {
    cout<<"9";
    return 0;
  }
  else if(k==0)
  {
    cout<<s;
    return 0;
  }

  for(i=0; i<n/2; i++)
    if(s[i] != s[(n-1)-i])
      ++count;

  if(count > k)
  {
    cout<<"-1";
    return 0;
  }

  long long int ext = k-count;

  for(i=0;i<n/2; i++)
  {
    if(s[i] == '9' && s[(n-1)-i] == '9')
    {
      continue;
    }
    else if(s[i] == '9' || s[(n-1)-i] == '9')
    {
        s[i] = '9';
        s[(n-1)-i] = '9';
      }
      else
      {
        if(ext>=1)
        {
          if(s[i] == s[(n-1)-i])
          {
            ext = ext-2;
          }
          else
          {
            --ext;
          }
          s[i] = '9';
          s[(n-1)-i] = '9';

        }
        else
        {
        if(s[i] > s[(n-1)-i])
          s[(n-1)-i] = s[i];
          else
          s[i] = s[(n-1)-i];
        }
      }
  }

for(i=0; i<n; i++)
cout<<s[i];

  return 0;
}
