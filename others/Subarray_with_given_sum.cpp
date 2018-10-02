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
  lli t,fla = 0;
  cin>>t;

  while(t>0)
  {
    lli n,s;
    cin>>n>>s;
    lli arr[n];

    cin>>arr[0];

    for(int i=1;i<n;i++)
    {
      cin>>arr[i];
      arr[i] = arr[i] + arr[i-1];
    }

    lli in=0,mn=0;
    lli che = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == s)
        {
          mn = i+1;
          in = in+1;
          fla =1;
          break;
        }

        if(arr[i] > s)
        {
          fla = 0;
          while(che < i)
          {
            if( (arr[i]-arr[che]) == s)
            {
              in = che+2;
              mn = i+1;
              fla = 1;
              break;
            }

            if( (arr[i]-arr[che]) < s)
            break;

            ++che;
          }
        }

        if(fla)
        break;
    }

    if(fla)
    cout<<in<<" "<<mn<<endl;
    else
    cout<<-1<<endl;

    fla = 0;
    --t;
  }
  return 0;
}
