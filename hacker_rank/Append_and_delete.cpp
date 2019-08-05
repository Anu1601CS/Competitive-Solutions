#include <bits/stdc++.h>
using namespace std;
#define SYNC                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007s
#define pi acos(-1.0)
#define eps 1e-8
#define all(c) c.begin(), c.end()

typedef long long int lli;

int equalSoFar(string s, string t)
{
  int i;
  for (i = 0; i < s.length(); i++)
  {
    if (s[i] != t[i])
      break;
  }

  return i;
}

int main()
{
  string s, t;
  cin >> s >> t;
  int s_l = s.length();
  int t_l = t.length();

  int k;
  cin >> k;

  if (abs(s_l - t_l) == 0)
  {
    int nec = abs(s_l - equalSoFar(s, t)) * 2;

    if (nec > k)
      cout << "No" << endl;
    else if ((nec == k) || (k - nec) >= 2 * s_l || (k - nec) % 2 == 0)
      cout << "Yes" << endl;
    else if ((k - nec) % 2 != 0 && equalSoFar(s, t) == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else
  {
    int cost = abs(s_l - t_l);

    if (cost > k)
    {
      cout << "No" << endl;
      return 0;
    }
    else
    {
      int nec = abs(t_l - equalSoFar(s, t)) * 2;

      if ((nec + cost == k) || (k - (nec + cost)) >= 2 * s_l || (k - (nec + cost)) % 2 == 0)
        cout << "Yes" << endl;
      else if ((k - nec + cost) % 2 != 0 && (k - nec + cost) >= equalSoFar(s, t) * 2)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}