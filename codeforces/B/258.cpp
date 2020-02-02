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

	for(auto &x : v) {
		cin>>x;
	}

	int l=0,h=0;

	for(int i=0;i<n-1;i++) {
		if(v[i] > v[i+1]) {
			l = i;
			break;
		}
	}

	for(int i=n-1; i>=0; i--) {
		if(v[i] < v[i-1]) {
			h = i;
			break;
		}
	}


	for(int k=l; k<h; k++) {
		if(v[k] < v[k+1]) {
			cout<<"no"<<endl;
			return 0;
		}
	}

	if((l==0 && h != n-1))  {
		if(v[l] > v[h+1]) {
			cout<<"no"<<endl;
			return 0;
		}
	} 

	if(l != 0 && h == n-1) {
		if(v[h] < v[l-1]) {
			cout<<"no"<<endl;
			return 0;
		}
	}

	if(l!=0 && h !=n-1) {
		if( (v[l] > v[h+1]) || (v[h] < v[l-1])) {
			cout<<"no"<<endl;
			return 0;
		}
	}

	cout<<"yes"<<endl;
	cout<<l+1<<" "<<h+1<<endl;


	return 0;
}