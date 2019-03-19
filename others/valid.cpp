#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;

  cin >> s;

  int ca = 0;
  int cb = 0;
  bool ans = true;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'a')
    {
      ++ca;
    }
    else
    {
      ++cb;

      if (ca < cb)
      {
        ans = false;
        break;
      }
      else
      {
        --ca;
        --cb;
      }
    }
  }

  if (ans && cb == 0 && ca == 0)
    cout << "VALID";
  else
    cout << "NOT VALID";

  return 0;
}
