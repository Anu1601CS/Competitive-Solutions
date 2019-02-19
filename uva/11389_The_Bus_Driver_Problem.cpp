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
typedef vector<int> vi1,vi2,vi3;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

bool myfunction (lli i,lli j) { return (i > j); }

int main()
{
  SYNC
  while(1)
  {
    lli mor[105],eve[105];
    lli n,d,r,i,j,total=0;
    cin>>n>>d>>r;

    if(n==0 && d == 0 && r==0)
      break;

    mor[n],eve[n];

    for(i=0; i<n; i++)
      cin>>mor[i];

    for(i=0; i<n; i++)
      cin>>eve[i];

    sort(mor, mor+n);
    sort(eve, eve+n);

    for(i=0; i<n; i++)
      if(mor[i] + eve[n-i-1] > d)
        total += (mor[i] + eve[n-i-1]-d) * r;

    cout<<total<<endl;
  }

  return 0;
}
