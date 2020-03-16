#include <bits/stdc++.h>
#include <string>
using namespace std;
#define SYNC                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/* <--------------------------------------------------------------------------------> */

int bc(int n){
	int c = 0;
	while(n > 0){
		if(n%2 == 1){
		 	++c;
		}
		n = n/2;
	}

	return c;
}

int main()
{
	SYNC

	int t;
	cin>>t;

	while(t--) {
		int n,q;
		cin>>n>>q;
		int ev = 0, od =0;

		for(int i=0; i<n; i++){
			int a;
			cin>>a;

			if(bc(a)%2 == 0){
				ev++;
			} else {
				od++;
			}

		}

		for(int i=0;i<q;i++){
			int p;
			cin>>p;

			if(bc(p)%2 ==0){
				cout<<ev<<" "<<od<<endl;
			} else {
				cout<<od<<" "<<ev<<endl;
			}
			
		}
	}

  return 0;
}
