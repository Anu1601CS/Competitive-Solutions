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
#define all(cc) (cc).begin(),(cc).end()
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)

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

  lli i,j,b,n,m;
  cin>>b>>n>>m;

  lli key[n],dri[m];

  for(i=0;i<n;i++)
  cin>>key[i];

  for(i=0;i<m;i++)
  cin>>dri[i];

  lli max  = -1;

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
      if(key[i]+dri[j] > max && key[i]+dri[j] <= b)
      max = key[i]+dri[j];
    }

  cout<<max<<endl;

  return 0;
}
