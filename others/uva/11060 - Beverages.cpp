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
  int n, m, cases = 0, x, y, top, i;
  char cmd[105], name[105][105];

  while(cin>>n)
  {
    if(n==0)
    break;

    map<string, int> R;
    vector<int> g[105];
    int indeg[105] = {};

    for(i = 0; i < n; i++)
    {
      cin>>name[i];
      R[name[i]] = i;
    }

    cin>>m;

    while(m--)
    {
      cin>>cmd;
      x = R[cmd];
      cin>>cmd;
      y = R[cmd];
      g[x].push_back(y);
      indeg[y]++;
    }

    priority_queue<int, vector<int>, greater<int> > Q;

    for(i = 0; i < n; i++)
      if(indeg[i] == 0)
        Q.push(i);

      cout<<"Case #"<<++cases<<": Dilbert should drink beverages in this order:";

      while(!Q.empty())
      {
        top = Q.top();
        Q.pop();
        for(vector<int>::iterator it = g[top].begin(); it != g[top].end(); it++)
        {
          indeg[*it]--;

          if(indeg[*it] == 0)
          Q.push(*it);
        }
            cout<<" "<<name[top];
      }
        puts(".\n");
    }
    return 0;
}
