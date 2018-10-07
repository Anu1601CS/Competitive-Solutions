#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

bool myfunction (lli i,lli j) { return (i > j); }
int sti (string s) { stringstream con(s); int x; con >> x; return x; }

int main()
{
  SYNC
  int n,s,a;
  cin>>n>>s;

  bool dp[n+1][s+1];

  vi set;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    set.push_back(a);
  }

  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=s;j++)
    {
      if(j==0 || i==0)
        dp[i][j] = true;
        else
        if(j < set[i])
        dp[i][j] = dp[i-1][j];

        if(j>=set[i-1])
        {
          dp[i][j] = dp[i-1][j-set[i]] || dp[i-1][j];
        }
    }
  }

  if(dp[n][s])
    cout<<"YES";

  return 0;
}
