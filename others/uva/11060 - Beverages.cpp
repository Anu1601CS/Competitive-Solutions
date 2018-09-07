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
vector<int>result;

int khans(vector<int>graph[], int v,int e)
{
  vector<int>indegree (v,0);

  vector<int>::iterator it,it2;
  for(int u=0;u<v;u++)
    for(it=graph[u].begin();it!=graph[u].end();it++)
        indegree[*it]++;

  priority_queue<int, vector<int>, greater<int> > q;
  for(int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);

  while(!q.empty())
  {
    int u = q.top();
    q.pop();
    result.push_back(u);

    for(it2=graph[u].begin(); it2!= graph[u].end(); it2++)
      if(--indegree[*it2] == 0 )
        q.push(*it2);
  }

  return 0;
}

int main()
{
  SYNC

  int count = 1,n;

  while(cin>>n)
  {
    int m,i;
    if(n == 0)
      break;

    map<string, int>ma;
    map<int, string>mare;
    vector<int>graph[105];

    string s;
    for(i=0;i<n;i++)
    {
      cin>>s;
      ma[s] = i;
      mare[i] = s;
      visited[i] = false;
    }

    cin>>m;

    for(i=0; i<m; i++)
    {
      string a,b;
      cin>>a>>b;
      graph[ma[a]].push_back(ma[b]);
    }

    khans(graph,n,m);

    cout<<"Case #"<<count<<": Dilbert should drink beverages in this order: ";

    for(int i=0; i<result.size();i++)
    {
      cout<<mare[result[i]];

      if(i < result.size()-1)
        cout<<" ";
    }
    cout<<".";

    ++count;
    cout<<endl;
  }

  return 0;
}
