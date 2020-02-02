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

typedef long long int lli;

int main()
{
	lli n;
	cin>>n;

	std::vector<lli> v(n);

	lli maxnum = 0;
	for(auto &x : v) {
		cin>>x;
		maxnum = max(maxnum, x);
	}

	lli dd = ceil(sqrt(maxnum));

	std::vector<bool> prime(dd+1, true);

	prime[0] = false, prime[1]= false;

	for(int p=2; p*p<=dd; p++) {
		if(prime[p] == true) {
			for(int j=p*p; j<=dd; j=j+p) {
				// cout<<j<<endl;
				prime[j] = false;
			}
		}
	}

	for(auto x: v) { 
		lli c = 0;
		for(lli i=2; i<=ceil(sqrt(x)); i++) {
			if(prime[i] == true) {
				if(x % i == 0) {
					// cout<<i<<endl;
					++c;
				}
			}
		}

		if(c == 1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}