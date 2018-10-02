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

int khans(vector<int>graph[100],vector<int> in_degree,int v,int e)
{
  queue<int> q;
  for(int i=0;i<v;i++)
  if(in_degree[i]==0)
    q.push(i);

  int count = 0;

   queue<int>result;
  while(!q.empty())
  {
    int top = q.front();
    q.pop();


    result.push(top);
    vector<int>::iterator it;

    for(it = graph[top].begin(); it!= graph[top].end(); it++)
    {
      if (--in_degree[*it] == 0)
               q.push(*it);
    }

    ++count;
  }

  if(count != v)
  cout<<"not a DAC graph";

  while(!result.empty())
  {
    cout<<result.front()<<" ";
    result.pop();
  }


return 0;
}

int main()
{
  SYNC

  int v,e;
  cin>>v>>e;
  int a,b;
  vector<int>graph[100];

  int indeg[v];

  vector<int> in_degree(v, 0);

  for(int i=0;i<v;i++)
  {
    cin>>a>>b;
    graph[a].push_back(b);
    in_degree[b]++;
  }

  khans(graph,in_degree,v,e);

  return 0;
}
