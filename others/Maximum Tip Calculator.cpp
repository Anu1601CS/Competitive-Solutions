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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

bool myfunction (lli i,lli j) { return (i > j); }
int sti (string s) { stringstream con(s); int x; con >> x; return x; }

bool comp(pair<int,int>a, pair<int,int>b)
{
  return (abs(a.first-a.second) > abs(b.first-b.second));
}

int main()
{
  int t;
  cin>>t;

  while(t>0)
  {
    int i,n,x,y;
    cin>>n>>x>>y;

    vector<pair<int,int>> vec(n);

    int a;
    for(i=0;i<n;i++)
    {
      cin>>a;
      vec[i].first = a;
    }

    for(i=0;i<n;i++)
    {
      cin>>a;
      vec[i].second = a;
    }

    sort(vec.begin(), vec.end(), comp);

    int total = 0;
    for(i=0;i<n;i++)
    {
      if(x>0 && (vec[i].first >= vec[i].second) || y==0)
      {
        total = total + vec[i].first;
        --x;
      }
      else
      if(y>0 && (vec[i].first<=vec[i].second) || x==0)
      {
        total = total + vec[i].second;
        --y;
      }
    }

    cout<<total<<endl;
    --t;
  }

  return 0;
}
