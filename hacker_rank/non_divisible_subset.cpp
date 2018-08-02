#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n,k,i,temp,result = 0;
  cin>>n>>k;

  long long int s[k];

  memset(s, 0, sizeof(s));

  for(i=0; i<n; i++)
  {
    cin>>temp;
    s[temp%k]+=1;
  }

  if(s[0] >= 1)
  {
    result++;
  }



  for(i=1;i<=k/2;i++)
  {
    if(k%2==0 && i==k/2)
    break;

    temp = s[i];

    if(s[k-i] > temp)
    {
      temp = s[k-i];
    }

    result+=temp;
  }

  if(k%2==0 && s[k/2]>0)
  ++result;

  cout<<result;
  return 0;
}
