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
  int t;
  cin>>t;

  while(t>0)
  {
    int n;
    cin>>n;

    int arr[n],dep[n];
    int a,b;
    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=0;i<n;i++)
    cin>>dep[i];

      sort(arr, arr+n);
      sort(dep, dep+n);

       int plat_needed = 1, result = 1;
       int i = 1, j = 0;

       while (i < n && j < n)
       {

          if (arr[i] <= dep[j])
          {
              plat_needed++;
              i++;

              if (plat_needed > result)
                  result = plat_needed;
          }
          else
          {
              plat_needed--;
              j++;
          }
       }

    cout<<result<<endl;
    --t;
  }


  return 0;
}
