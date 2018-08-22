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
lli l,r,x,y;
bool ft(lli a){
    a=a*x;
    if(a<=r && a>=l) return 1;
    return 0;
}

int main()
{
  SYNC

  lli a,b,x,y,z;
  cin>>a>>b;
  cin>>x>>y>>z;

  lli rb=0,ry=0;

  if(x!=0)
  {
    ry = ry + 2 * x;
  }

  if(y!=0)
  {
    ry = ry + y;
    rb = rb + y;
  }

  if(z!=0)
  {
    rb = rb + 3 * z;
  }

  if(x==0 && y==0 && z==0)
  {
      cout<<0;
      return 0;
  }

  lli total = 0;

  if(ry!=0 && ry > a)
  {
    total = total + abs(ry-a);
  }

  if(rb!=0 && rb > b)
  {
    total = total  + abs(rb-b);
  }

  cout<<total;

  return 0;
}
