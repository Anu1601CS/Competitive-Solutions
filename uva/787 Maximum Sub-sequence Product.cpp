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
  lli n;
  vi arr;
  while(cin>>n)
  {
    if(n==-1000000)
    break;
    arr.push_back(n);
    if(n == -999999)
    {
      lli i,j,temp=1,p=0,max=arr[0];
      for(i=0;i<arr.size()-1;i++)
      {
        for(j=i;j<arr.size()-1;j++)
        {
          temp = temp * arr[j];
          if(temp > max)
          max = temp;
        }
        temp = 1;
      }

      cout<<max<<endl;
      arr.clear();
    }
  }
  return 0;
}
