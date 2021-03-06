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

long int cou;
bool visited[100000] = {false};

int dfs(vector<lli> vec[], lli u)
{
  visited[u] = true;

  vector<lli>::iterator it;

  for(it=vec[u].begin(); it!=vec[u].end(); it++)
  {
    if(!visited[*it])
    {
      ++cou;
      dfs(vec,*it);
    }
  }

  return cou;
}

int main()
{
  SYNC

  lli i,a,b;
  lli n,p;

  cin>>n>>p;
  lli c=0,arr[n];

  vector<lli>::iterator vit;
  vector<lli> vec[100000];

  for(i=0; i<p; i++)
  {
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  lli total = 0;
  lli prev = 0;

  for(i=0; i<n; i++)
  {
    cou = 1;
    if(!visited[i])
    {
      lli count = dfs(vec,i);
      total = total + (prev * count);
      prev += count;
    }
  }

  cout<<total;

  return 0;
}
