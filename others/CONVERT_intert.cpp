#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findDiff(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  if (n != m)
  {
    cout << "Not Possible." << endl;
    return 0;
  }

  list<char> ls;

  for (auto i : s1)
    ls.push_back(i);

  int ans = 0;

  int i = m - 1;
  while (i >= 0)
  {
    char back = ls.back();

    if (s2[i] == back)
    {
      i--;
    }
    else
    {
      ans++;
      ls.push_front(back);
    }

    ls.pop_back();
  }

  cout << ans << " ";

  return 0;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  findDiff(s1, s2);

  return 0;
}
