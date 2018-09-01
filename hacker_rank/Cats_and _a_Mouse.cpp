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

bool myfunction (lli i,lli j) { return (i<j); }

int main()
{
  SYNC

  lli x,y,z,q,i;

  cin>>q;

  vector<int> re;
  vector<int> :: iterator it;

  for(i=0;i<q;i++)
  {
    cin>>x>>y>>z;

    if(abs(z-x) < abs(z-y))
    re.push_back(1);
    else if(abs(z-x) > abs(z-y))
    re.push_back(2);
    else if(abs(z-x) == abs(z-y))
    re.push_back(0);
  }

  for(it=re.begin(); it!= re.end(); it++)
  {
    if(*it == 1)
    cout<<"Cat A"<<endl;
    else
    if(*it == 2)
    cout<<"Cat B"<<endl;
    else
    if(*it == 0)
    cout<<"Mouse C"<<endl;

  }

  return 0;
}
