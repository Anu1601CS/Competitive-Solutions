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
typedef vector<int> vi1,vi2,vi3;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

bool myfunction (lli i,lli j) { return (i > j); }

lli findbill(lli bill[], lli n, lli p)
{
  lli total = 0,j,min = INT_MAX,i,tam,count = 0,num;

  for(i=0;i<n;i++)
  {
    total = 0;
    count = 0;

    for(j=i;j<n;j++)
    {
      if(p < bill[j])
      {
        lli d = bill[j]-p;

        if(min > d)
        {
          min = d;
          tam = bill[j];
          num = 1;
        }
        continue;
      }

      if(p == bill[j])
      {
        tam = bill[j];
        num = 1;
        cout<<tam<<" "<<num<<endl;
        return 0;
      }

      total += bill[j];
      ++count;

      if(total > p)
      {
        lli d = total-p;

        if(min > d)
        {
          min = d;
          tam = total;
          num = count;
        }
        break;
      }

      if(p == total)
      {
        tam = total;
        num = count;
        cout<<tam<<" "<<num<<endl;
        return 0;
      }

    }
  }

  cout<<tam<<" "<<num<<endl;
  return 0;
}

int main()
{
  SYNC
  lli test;
  cin>>test;

  while(test>0)
  {
    lli p,n,i;
    cin>>p>>n;

    lli bill[n];

    for(i=0;i<n;i++)
      cin>>bill[i];

    sort(bill, bill+n, myfunction);

    findbill(bill, n, p);

    --test;
  }

  return 0;
}
