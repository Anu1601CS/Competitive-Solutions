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

  lli i,n,q,a,b;
  cin>>n>>q;
  set<int> myset;
  for(i=1;i<=q;i++)
  {
    cin>>a>>b;
    if(a==1){ myset.insert(b);}
    else
    {
      lli val = *myset.lower_bound(b);
      if(val < b)
      cout<<-1<<endl;
      else
      cout<<val<<endl;
    }
  }
  return 0;
}
