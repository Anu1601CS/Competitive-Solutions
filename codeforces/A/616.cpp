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

	int t;
	cin>>t;

	while(t--) {

		int n;
		cin>>n;
		string s;
		cin>>s;

		int sum = 0;
		vector<int>myVec;

		for(int i=0;i<n;i++) {
				if((s[i] - '0') % 2 == 1) myVec.push_back(s[i]-'0');
		}

		if(myVec.size()< 2) cout<<-1<<endl;
		else 
			cout<<myVec[0]<<myVec[1]<<endl;

	}
	
	return 0;
}