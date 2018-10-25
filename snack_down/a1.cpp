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
  int t;
  cin>>t;

  while(t>0)
  {
    int n,m;
    cin>>n>>m;

    int arr[n+1][m+1];

    int cp = 0;
    pair<int,int>pa[n*m];

    string s;

    for(int i=1;i<=n;i++)
    {
      cin>>s;
      for(int j=1;j<=m;j++)
      {
        if(s[j-1] == '1')
        {
            pa[cp++] = make_pair(i,j);
        }
      }
    }

    int d = n+m-2;

    int count[d+1];

    memset(count, 0, sizeof(count));

    for(int i=0;i<cp;i++)
    {
      for(int j=i+1;j<cp;j++)
      {
        int val = abs(pa[i].first - pa[j].first) + abs(pa[i].second - pa[j].second);
        count[val]++;
      }
    }

    for(int i=1;i<=d;i++)
    cout<<count[i]<<" ";

    --t;
  }
  return 0;
}
