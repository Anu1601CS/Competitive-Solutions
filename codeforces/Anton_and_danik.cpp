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
lli l,r,x,y;

bool ft(lli a){
	a=a*x;
	if(a<=r && a>=l) return 1;
	return 0;
}

int main()
{
  SYNC
	lli n,k,a,b,c,i,j,c=0,c1=0,c2=0;
	string s,s1,s2;

	cin>>n;
	cin>>s;

	for(i=0;i<n;i++)
		if(s[i]=='A')
			++c;
			else
			++c1;

	if(c>c1)
		cout<<"Anton";
		else
		if(c<c1)
		cout<<"Danik";
		else
		cout





return 0;
}
