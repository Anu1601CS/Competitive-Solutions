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
	int n;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	int min = v[0];

	for(int i=1; i<n-1; i++) {
		if(min < 0) {

			if(v[i] > 0) {
				min =  min * v[i];
			} else  if(v[i] < 0 && v[i+1] < 0) {
				min = min * v[i];
			}

		} else if(v[i] < 0) {
			min = min * v[i];
		} else {
			break;
		}
	}

	if(min < 0 && v[n-1] > 0) {
		min = min * v[n-1];
	}

	cout<<min<<endl;


	
	return 0;
}