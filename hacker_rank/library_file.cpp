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

int main()
{
  int d1, m1, y1;
  int d2, m2, y2;

  cin >> d1 >> m1 >> y1;
  cin >> d2 >> m2 >> y2;

  if (y1 < y2)
  {
    cout << 0 << endl;
    return 0;
  }

  if (y1 <= y2 && m1 < m2)
  {
    cout << 0 << endl;
    return 0;
  }

  if (y1 != y2 && y1 > y2)
    cout << 10000 << endl;
  else if (m1 != m2 && m1 > m2)
    cout << (m1 - m2) * 500 << endl;
  else if (d1 != d2 && d1 > d2)
    cout << 15 * (d1 - d2) << endl;
  else
    cout << 0 << endl;

  return 0;
}