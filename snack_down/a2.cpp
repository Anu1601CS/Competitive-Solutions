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
  int t;
  cin>>t;

  while(t>0)
  {
    int n,m;
    cin>>n;

    string s;

    double total = 0.0,pa= 0.0;

    map<string,double>mymap;
    map<string,double>::iterator it;

    for(int i=0;i<n;i++)
    {
      cin>>s;
      pa = 0.0;

      it = mymap.find(s);

      if(it != mymap.end())
      {
        total = total + ( mymap.find(s)->second )/2;
        continue;
      }

      pa = 0.2;
      for(int j=1;j<s.length();j++)
      {
        if( (s[j] == 'd' && s[j-1] == 'f') || (s[j]=='f' && s[j-1] == 'd') )
        {
          pa = pa + 0.4;
        }
        else if( (s[j] == 'j' && s[j-1] == 'k') || (s[j]=='k' && s[j-1] == 'j') )
        {
          pa = pa + 0.4;
        }
        else if( (s[j] == 'k' && s[j-1] == 'k') || (s[j]=='j' && s[j-1] == 'j') )
        {
          pa = pa + 0.4;
        }
        else if( (s[j] == 'd' && s[j-1] == 'd') || (s[j]=='f' && s[j-1] == 'f') )
        {
          pa = pa + 0.4;
        }
        else
        {
          pa = pa + 0.2;
        }
      }

      mymap[s] = pa;
      total = total  + pa;
    }

    cout<<total*10<<endl;

    --t;
  }
  return 0;
}
