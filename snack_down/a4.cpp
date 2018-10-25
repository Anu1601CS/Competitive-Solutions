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

bool visited[100];

void dfs(int arr[], int start, int n)
{
  visited[start] = true;

  for(int i = 1; i<=n; i++)
  {
    if(!visited[i] &&  (__gcd(arr[i], arr[start]) == 1) )
    {
      dfs(arr, i,n);
    }
  }
}

int main()
{
  SYNC
  int t;
  cin>>t;

  while(t>0)
  {
    int n;
    cin>>n;

    int arr[n];

    int carr[100];

    memset(carr, 0, sizeof(carr));

    for(int i=1; i<=n; i++)
    {
      cin>>arr[i];
      carr[arr[i]]++;
    }

    memset(visited, false, sizeof(visited));

    dfs(arr, 1, n);

    int count = 0;

    for(int i=1;i<=n;i++)
    {
      if(!visited[i])
      ++count;
    }

    if(count == 0)
    {
      cout<<"0"<<endl;
      for(int i=1;i<=n;i++)
      cout<<arr[i]<<" ";
    }
    else
    {
      cout<<"1"<<endl;

      if(carr[29] == n || carr[31] == n || carr[37] == n|| carr[41] == n || carr[43] == n || carr[47] == n)
      {
        cout<<"7"<<" ";

        for(int i=2;i<=n;i++)
          cout<<arr[i]<<" ";
      }
      else
      {
        cout<<"47"<<" ";

        for(int i=2; i<=n; i++)
          cout<<arr[i]<<" ";
      }
    }

    cout<<endl;
    --t;
  }


  return 0;
}
