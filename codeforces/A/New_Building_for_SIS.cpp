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
	lli n,h,a,b,k,ta,tb,fa,fb,re,i;
	vector<int> result;

	cin>>n>>h>>a>>b>>k;

	for(i=0;i<k;i++)
	{
		cin>>ta>>fa>>tb>>fb;

		if(ta==tb)
		{
			result.push_back(abs(fa-fb));
		}
		else
		if(abs(ta-tb) == 1)
		{
			if(fa>=a && fa<=b)
			{
				re = 1+ abs(fa-fb);
				result.push_back(re);
			}
			else
			if(fa>b)
			{
				re = abs(fa-b) + 1 + abs(fb-b);
				result.push_back(re);
			}
			else
			if(fa<a)
			{
				re = abs(fa-a) + 1 + abs(fb-a);
				result.push_back(re);
			}
		}
		else
		if(abs(ta-tb) > 1)
		{
			if(fa>=a && fa<=b)
			{
				re = abs(fa-fb) + abs(ta-tb);
				result.push_back(re);
			}
			else
			if(fa>b)
			{
				re = abs(fa-b) + abs(fb-b) + abs(ta-tb);
				result.push_back(re);
			}
			else
			if(fa<a)
			{
				re = abs(fa-a) +  abs(fb-a) + abs(ta-tb);
				result.push_back(re);
			}

		}
	}

	vector<int>::iterator itv;

	for(itv=result.begin(); itv != result.end() ; itv++)
	cout<<*itv<<endl;

  return 0;
}
