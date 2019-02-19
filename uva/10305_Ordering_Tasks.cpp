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

stack<int>st;
bool visited[105];

int dfs(vector< int >graph[], bool visited[], int start)
{
  visited[start] = true;

  vector< int >:: iterator it;

  for(it=graph[start].begin(); it!= graph[start].end(); it++)
  {
    if(!visited[*it])
      dfs(graph,visited,*it);
  }

st.push(start);
return 0;
}

int main()
{
  SYNC

  while(1)
  {
    int n,m,i;
    cin>>n>>m;

    if(n == 0 && m == 0)
      break;

    vector< int >graph[105];

    for(i=1;i<=n;i++)
    visited[i] = false;

    for(i=0; i<m; i++)
    {
      int a,b;
      cin>>a>>b;

      graph[a].push_back(b);
    }

    for(i=1;i<=n;i++)
    if(!visited[i])
    dfs(graph,visited,i);

    while(!st.empty())
    {
      cout<<st.top();
      if(st.size() > 1)
      cout<<" ";
      st.pop();
    }
    cout<<endl;
  }

  return 0;
}
