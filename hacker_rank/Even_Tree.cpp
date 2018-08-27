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

bool visited[99999];

int dfs(vector<int>graph[], int *ans, int v)
{
  int num = 0, temp = 0;

  visited[v] = true;

  vector<int>::iterator i;

  for(i = graph[v].begin(); i != graph[v].end(); i++)
  {
    if(!visited[*i])
    {
      temp  = dfs(graph,ans,*i);

      (temp%2)?(num += temp):((*ans)++);
    }

  }

return num+1;
}

int main()
{
  SYNC
  int v,e,i,j,a,b;

  cin>>v>>e;

  int ans = 0;
  vector<int> graph[99999];

  for(i=0;i<e;i++)
  {
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  memset(visited, false, sizeof(visited));

  dfs(graph, &ans,1);

  cout<<ans;
  return 0;
}
