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
  int t;
  cin>>t;

  int _t = 0;

  while(1)
  {
    if(_t==t)
      break;

    int n,i,count = 0,c1 = 0;
    string s;
    cin>>n;
    cin>>s;

    for(i=0;i<n;i++)
    {
      if(c1==0 && s[i] == '#')
        continue;

      if(s[i]=='.')
        ++c1;

      if(c1 == 3)
      {
        c1 = 0;
        ++count;
        continue;
      }

      if(c1!=0 && c1<3 && s[i]=='#')
      {
        c1 = 0;
        i++;
        ++count;
      }
    }

    if(c1>0 && c1 < 3)
    ++count;

    cout<<c1<<endl;
    cout<<"Case "<<_t+1<<": "<<count<<endl;

    ++_t;
  }

  return 0;
}
