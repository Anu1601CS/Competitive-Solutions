#include <bits/stdc++.h>
using namespace std;
#define SYNC                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second

typedef long long int lli;

int main()
{
  SYNC

      string str,
      pattern;
  cin >> str >> pattern;

  bool dp[str.length() + 1][pattern.length() + 1];
  
  dp[0][0] = true;

  for (int i = 1; i <= str.length(); i++)
    dp[i][0] = false;

  for (int j = 1; j <= pattern.length(); j++)
    dp[0][j] = false;

  for (int i = 1; i <= str.length(); i++)
  {
    for (int j = 1; j <= pattern.length(); j++)
    {
      if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else if (pattern[j - 1] == '*')
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      else
        dp[i][j] = false;
    }
  }

  for (int i = 0; i <= str.length(); i++)
  {
    for (int j = 0; j <= pattern.length(); j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  if (dp[str.length()][pattern.length()])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
