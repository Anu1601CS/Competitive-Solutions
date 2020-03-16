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

int main()
{
	SYNC

	int t;
	cin>>t;

	while(t--){
		int n,m;
		cin>>m>>n;

		minpq <int> res;
		unordered_map<int,int>myMap;
		vector<int>f;
		for(int i=0; i<m; i++) {
			int a;
			cin>>a;
			f.push_back(a); 
		}

		vector<int>p;
		for(int i=0; i<m; i++) {
			int a;
			cin>>a;
			p.push_back(a); 
		}

		int min = INT_MAX;
		for(int i=0; i<m; i++){
			myMap[f[i]] = myMap[f[i]] + p[i];
		}
		
		for(int i=0; i<m; i++){
			if(min > myMap[f[i]]) {
				min = myMap[f[i]];
			}
		}

		cout<<min<<endl;

	}

  return 0;
}
