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

int main()
{
  SYNC
  int n;
  cin>>n;

  int arr[n];
  int lis[n];

  lis[0]=1;

  for(int i=0;i<n;i++)
    cin>>arr[i];

  for(int i=1;i<n;i++)
  {
    lis[i] =1;
    for(int j=0;j<i;j++)
    {
      if(arr[j] < arr[i] && lis[j]+1 >= lis[i])
        lis[i] = lis[j]+1;
    }
  }

  cout<<*max_element(lis,lis+n);
  return 0;
}
