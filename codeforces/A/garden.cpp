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
	int n,k;
	cin>>n>>k;
	int arr[n];

	int i;
	int max = 0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];

		if(k%arr[i] == 0)
		{
			if(max < arr[i])
				max  = arr[i];
		}

	}
int count = 0;

int a = max;
while(a<=k)
{
	count++;
	a = a + max;
}

cout<<count<<endl;
return 0;
}
