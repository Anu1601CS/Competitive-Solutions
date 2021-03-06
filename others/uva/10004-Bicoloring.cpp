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

int col = 0;
int color[300];
int check = 1;

int isBiparted(vector<int>graph[], bool visited[],int v, int col)
{
  if(!check)
  return 0;

  visited[v] = true;
  color[v] = col;

  vector<int>::iterator itr;

  for(itr = graph[v].begin(); itr != graph[v].end(); itr++)
  {
    if(!visited[*itr])
      isBiparted(graph, visited, *itr, 1 - col);
      else
      if(color[*itr] == col)
      {
        check = 0;
        return 0;
      }
  }
  return 0;
}

int main()
{
  SYNC

  lli n,l;

  while(cin>>n)
  {
    if(n==0)
    break;

    cin>>l;
    vector<int>graph[500];

    lli i,a,b;
    for(i=0;i<l;i++)
    {
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    bool visited[n];
    for(i=0;i<n;i++)
    visited[i] = false;

    isBiparted(graph,visited,0,1);

    if(check)
    cout<<"BICOLORABLE."<<endl;
    else
    cout<<"NOT BICOLORABLE."<<endl;

    check  = 1;
  }
  return 0;
}
