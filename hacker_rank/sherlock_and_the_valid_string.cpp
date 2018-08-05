#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int count = 0 ,size= 0,check, max = 0,min = 999999;
  map<char,int>::iterator v;
  map<char,int> map;
  int arr[100000];

  memset(arr, 0, sizeof(arr[0]));

  string s;
  cin>>s;

  for(int i=0; i<s.length(); i++)
  {
    int temp = arr[s[i]]+=1;
    map[s[i]] = temp;
  }

  check = map.begin()->second;

  for(v = map.begin(); v!= map.end(); v++)
  {
    ++size;
    if(check != v->second)
    {
      ++count;

      if(abs(check - v->second) == 1 && count <= 1)
      {
        continue;
      }
      else
      if(abs(check - v->second) != 1 && count == 1 && size == map.size())
      {
        continue;
      }
      else
      {
        cout<<"NO";
        return 0;
      }
    }
  }

  cout<<"YES";
  return 0;
}
