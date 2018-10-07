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

  string s1,s2;

  cin>>s1>>s2;

  int dp[s1.length()+1][s2.length()+1];

  for(int i=0;i<=s1.length();i++)
  {
    for(int j=0;j<=s2.length();j++)
    {
      if(j==0 || i==0)
        dp[i][j] = 0;
        else
        {
          if(s1[i-1]==s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
  }

  cout<<dp[s1.length()][s2.length()];
  return 0;
}
