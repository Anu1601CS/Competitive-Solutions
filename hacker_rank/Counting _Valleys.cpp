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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vlli;
typedef vector<pair<int,int> > vpii;

int main()
{
  SYNC
	lli n,k,a,b,c,d,i,j,co=0,co1=0,co2=0,check=1,temp;
	string s,t,s1,s2;

	cin>>n;
	cin>>t;

	for(i=0;i<n;i++)
	{

		if(t[i] == 'U')
			co = co - 1;
			else
			if(t[i] == 'D')
			co = co + 1;

		if(co > 0)
			c = 1;

		if(co <= 0 && c == 1)
		{
			c = 0;
			++co1;
		}
	}
	cout<<co1;
	return 0;
}
