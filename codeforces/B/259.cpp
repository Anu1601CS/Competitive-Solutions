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
	vector<lli> v;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		v.push_back(x);
	}

	lli c=0;
	lli pos;

	for(lli i = v.size()-1; i>=0; i--){
		if(c>2) break;

		if(v[i] < v[i-1]) {
			++c;
			pos = i;
		} 
	}	

	if(c == 1){ 
		if(v[v.size()-1] <= v[0]) {
			cout<<v.size()-pos<<endl; 
		} else {
			cout<<-1<<endl;
		}
	} else if(c==0) {
		cout<<c<<endl;
	} else {
		cout<<-1<<endl;
	}


	return 0;
}