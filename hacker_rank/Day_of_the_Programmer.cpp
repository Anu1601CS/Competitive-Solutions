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
lli l,r,x,y;
bool ft(lli a){
    a=a*x;
    if(a<=r && a>=l) return 1;
    return 0;
}

int main()
{
  SYNC
	int year;

	cin>>year;

	if(year == 1918)
	{
		cout<<"26.09.1918";
		return 0;
	}
	else if( (year <= 1917) && (year%4 == 0) )
	{
		cout<<"12.09."<<year;
		return 0;
	}
	else if( (year > 1918) && ( year%400 == 0 || ((year%4 == 0) && (year%100 != 0))) )
	{
		cout<<"12.09."<<year;
	}
	else
	{
		cout<<"13.09."<<year;
	}

return 0;
}
