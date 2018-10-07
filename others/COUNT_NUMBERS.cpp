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
  lli t;
  cin>>t;
  while(t>0)
  {
    lli n;
    string s;
    cin>>n;
    cin>>s;

    int count = 0,maxtill= 0;
    for(int i=0;i<n;i++)
    {
      if(48<=int(s[i]) && int(s[i])<=57)
      {
        maxtill=1;
        continue;
      }
      else
      {
        if(maxtill)
        {
          ++count;
          maxtill = 0;
        }
      }
    }

    if(maxtill==1)
      ++count;

    cout<<count<<endl;
    --t;
  }
  return 0;
}
