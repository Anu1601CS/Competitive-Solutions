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


lli count( lli S[], lli m, lli n )
{
    lli i,j,x,y;

    lli table[n+1][m];

    for (i=0;i<m;i++)
        table[0][i]=1;

    for (i=1;i<n+1;i++)
    {
        for (j=0;j<m;j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

int main()
{
  SYNC

  lli  n;
  lli coins[5] = {1,5,10,25,50};

  ifstream inFile;

  inFile.open("/opt/lampp/htdocs/comp/input.txt");

  while(inFile>>n)
  {
    if(count(coins,5,n)==1)
      cout<<"There is only "<<count(coins,5,n)<<" way to produce "<<n<<" cents change."<<endl;
      else
      cout<<"There are "<<count(coins,5,n)<<" ways to produce "<<n<<" cents change."<<endl;
  }

  return 0;
}
